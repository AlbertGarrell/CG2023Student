//Pràctica 4

varying vec2 v_uv;
uniform sampler2D u_texture;
uniform float u_fsopt;
void main()
{
	//vec4 texture_color = texture2D(u_texture, v_uv);
	//gl_FragColor = texture_color;
	//vec4 gl_FragColor;

//Ex 3.2.a
	//if(u_fsopt== 0.0){ /*3.2 z*/ //Lletra a
	//	vec4 texture_color = texture2D(u_texture, v_uv);
      //  float grisos = (texture_color.x + texture_color.y+ texture_color.z )/3 ; // Convertir a escala de grises
        //gl_FragColor = vec4(vec3(grisos),1.0);
	//}


//Ex 3.2.a
//	if(u_fsopt== 10.0){ /*3.2 b*/ //Lletra b
		//vec4 texture_color = texture2D(u_texture, v_uv);
    	//vec3 invert_color = vec3(1.0-texture_color.x,1.0-texture_color.y, 1.0-texture_color.z) ; // Convertir a escala de grises
    	//gl_FragColor = vec4(vec3(invert_color),1.0);
//	}
	//	if(u_fsopt== 10.0){ /*3.2 c*/ //Lletra c
		//vec4 texture_color = texture2D(u_texture, v_uv);
    	//vec3 invert_color = vec3( 1.0-texture_color.x,texture_color.y, texture_color.z) ; 
    	//gl_FragColor = vec4(vec3(invert_color),1.0);
	
	//vec4 texture_color = texture2D(u_texture, v_uv);
    
    // Swap the red and green channels
    //vec3 swapped_color = vec3(1-texture_color.y, texture_color.x, texture_color.z);
    
    //gl_FragColor = vec4(vec3(swapped_color),1.0);

		//if(u_fsopt== 0.0){ /*3.2 d*/ //Lletra d
	//vec4 texture_color = texture2D(u_texture, v_uv);
	//float constant = 0.5;
    //float grisos = (texture_color.x + texture_color.y+ texture_color.z )/3; // Convertir a escala de grises
    //gl_FragColor = vec4(vec3(step(constant, grisos)),1.0);
	//}

	vec4 texture_color = texture2D(u_texture, v_uv);
	vec2 center= vec2(0.5,0.5);
	float dist= distance( v_uv, center);
	//float degradado= smoothstep(0.5,0.5-0.3,dist);
	gl_FragColor = texture_color* dist;
	


	//else{
	//	vec4 texture_color = texture2D(u_texture, v_uv);
	//	gl_FragColor = texture_color;
	//}

}
