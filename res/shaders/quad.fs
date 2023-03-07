//Pràctica 4

varying vec2 v_uv;
uniform float u_option; //uniform variable que passem des del render d'aplication

void main()
{
	//Forma 1 de decidir color
	//Forma 2 de decidir color
	//vec3 color = v_uv.x * vec3(0,0,1) + (1-v_uv.x)* vec3(1,0,0);

	//Forma3 per decidir color interpolat

	/*3.1 a*/ //2 mètodes per fer-ho
	//vec3 color = vec3(v_uv.x, 0, 1-v_uv); //RGB
	//vec3 color = mix(vec3(0,0,1),vec3(1,0,0), v_uv.x); //ultim param factor interpolació c1*f + c2*(1-f), de blau a vermell en funció de les x en aqst cas
	//la x va der 0 a 1, per això actua com a fator conversió -> coord text van de 0 a 1

	//Pintar vermell sense calcular color
	//gl_FragColor = vec4(1.0,0.0,0.0,1.0); //hauria de pintar vermell

	//Per pintar forma1 o 2 o 3
	
	vec3 color;


	//gl_FragColor = vec4(v_uv.x,v_uv.y, 0.0, 1.0);

	//vec3 color= vec3(1,1,0);


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

	}
	else if(u_option == 5.0){ /*3.1 f*/ //Lletra f
		float step_x = step(v_uv.x*10,(floor(v_uv.x*10)+(floor(v_uv.x*10)+1))/2);
    	float step_y = step(v_uv.y*10,(floor(v_uv.y*10)+(floor(v_uv.y*10)+1))/2);
    	color = vec3(1.0) * mod((step_x + step_y),2);
	}



	else if(u_option == 10.0){ //Lletra j
		//color = vec3(0,1-sin(v_uv.y),0);
		color = sin(v_uv.y) * vec3(0,1,0);// + sin((1-v_uv.x))* vec3(0,1,0);
	}
	else if(u_option == 11.0){ //Lletra k
		//color = vec3(1.0) * step(v_uv.y*10,(floor(v_uv.y*10)+(floor(v_uv.y*10)+1))/2);
		float step_x = step(v_uv.x*10,(floor(v_uv.x*10)+(floor(v_uv.x*10)+1))/2);
    	float step_y = step(v_uv.y*10,(floor(v_uv.y*10)+(floor(v_uv.y*10)+1))/2);
    	color = vec3(1.0) * mod((step_x + step_y),2);
	}
	else if(u_option == 12.0){ //Lletra l
		color = vec3(0,sin(floor(v_uv.x*10)),sin(floor(v_uv.y*10)));
		//color = vec3(1.0) * step(0.5,v_uv.y);// - vec3(1.0) * step(0.5,v_uv.x);
	}

	else{
		color = vec3(1.0,0.0,0.0);
	}


	gl_FragColor = vec4(color,1.0);
	
}
