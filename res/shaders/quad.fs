//Pràctica 4

varying vec2 v_uv;
uniform float u_option; //uniform variable que passem des del render d'aplication

void main()
{
	vec3 color;

	if(u_option == 0.0){ /*3.1 a*/ //Lletra a
		//Fan el mateix els 2
		//color = mix(vec3(0,0,1),vec3(1,0,0), v_uv.x);
		color = v_uv.x * vec3(1,0,0) + (1-v_uv.x)* vec3(0,0,1);
	}
	else if(u_option == 1.0){ /*3.1 b*/ //Lletra b
		color = distance(vec2(v_uv.x, v_uv.y), vec2(0.5,0.5)) * vec3(1,1,1);
		//color = distance(v_uv.x, 0.5) * vec3(1,1,1) + distance(v_uv.y, 0.5) * vec3(1,1,1);
	}
	else if(u_option == 2.0){ /*3.1 c*/ //Lletra c
		color = vec3(sin(v_uv.x * 50), 0.0, sin(v_uv.y * 50)); 
	}
	else if(u_option == 3.0){ /*3.1 d*/ //Lletra d
		color = vec3(floor(v_uv.x*15)/15, floor(v_uv.y*15)/15, 0.0);
		//color = vec3(v_uv.x, v_uv.y,0);
	}
	else if(u_option == 4.0){
		//
	}
	else if(u_option == 5.0){ /*3.1 f*/ //Lletra f
		float step_x = step(v_uv.x*10,(floor(v_uv.x*10)+(floor(v_uv.x*10)+1))/2);
    	float step_y = step(v_uv.y*10,(floor(v_uv.y*10)+(floor(v_uv.y*10)+1))/2);
    	color = vec3(1.0) * mod((step_x + step_y),2);
		//color = vec3(1.0) * abs(step_x - step_y);
	}
	else if(u_option == 10.0){ //Lletra j
		//color = vec3(0,1-sin(v_uv.y),0);
		color = sin(v_uv.y) * vec3(0,1,0);// + sin((1-v_uv.x))* vec3(0,1,0);
	}
	else if(u_option == 11.0){ //Lletra k
		//color = distance(v_uv.y, 0.5) * vec3(0,1,0);
		color = vec3(0.0,sin(v_uv.y*5),0.0);
	}
	else if(u_option == 12.0){ //Lletra l
		color = vec3(0,sin(floor(v_uv.x*10)),sin(floor(v_uv.y*10)));
		//color = vec3(1.0) * step(0.5,v_uv.y);// - vec3(1.0) * step(0.5,v_uv.x);
	}
	else{
		color = vec3(1.0);
	}

	gl_FragColor = vec4(color,1.0);
}
