//Pràctica 4

varying vec2 v_uv;
uniform sampler2D u_texture;
uniform float u_option; 



void main()
{
	vec4 texture_color = texture2D(u_texture, v_uv);

//Ex 3.2.a
	if(u_option== 0.0){ /*3.2 a*/ //Lletra a

        float grisos = (texture_color.x + texture_color.y+ texture_color.z )/3;
		texture_color =  vec4(vec3(grisos),1.0);
       
	}


//Ex 3.2.b
	else if(u_option== 1.0){ /*3.2 b*/ //Lletra b
    	vec3 invert_color = vec3(1.0-texture_color.x,1.0-texture_color.y, 1.0-texture_color.z);
		texture_color = vec4(vec3(invert_color),1.0);
    	
	}

//Ex3.2.c
	else if(u_option== 2.0){ /*3.2 c*/ //Lletra c
    	vec3 channel_color = vec3( 1.0-texture_color.y,texture_color.x, texture_color.z); 
		texture_color = vec4(vec3(channel_color),1.0);   	
	}

//Ex3.2.d
	else if(u_option== 3.0){ /*3.2 d*/ //Lletra d
		float constant = 0.5;
    	float grisos = (texture_color.x + texture_color.y+ texture_color.z )/3; 
		texture_color =  vec4(vec3(step(constant, grisos)),1.0);
	}
//Ex3.2.e
	else if(u_option== 4.0){ /*3.2 e*/ //Lletra e

	}
//Ex3.2.f
	else if(u_option== 5.0){ /*3.2 f*/ //Lletra f
		float dist = distance(vec2(v_uv.x, v_uv.y), vec2(0.5,0.5));
		texture_color = texture_color*(1-dist);	
	}

	else{

	}
	gl_FragColor = texture_color;
}
