//Pràctica 4

varying vec2 v_uv;
uniform float u_option; //uniform variable que passem de ...

void main()
{
	//Forma 1 de decidir color
	
	//vec3 color = mix(vec3(0,0,1),vec3(1,0,0), v_uv.x); //ultim param factor interpolació c1*f + c2*(1-f), de blau a vermell en funció de les x en aqst cas
	//la x va der 0 a 1, per això actua com a fator conversió -> coord text van de 0 a 1

	//Forma 2 de decidir color
	//vec2 color = v_uv.x * vec3(0,0,1) + (1-v_uv.x)* vec3(1,0,0);

	//Forma3 per decidir color interpolat
	//vec3 color = vec3(1-v_uv.x, 0, v_uv);  

	//Pintar vermell sense calcular color
	
	gl_FragColor = vec4(0.2,0.7,0.3,1.0); //hauria de pintar vermell

	//Per pintar forma1 o 2 o 3
	//gl_FragColor = vec4(color, 1.0); 

	//gl_FragColor = vec4(v_uv.x,v_uv.y,0,1.0);

	//vec3 color= vec3(1,1,0);

	//if(u_option == 1){
	//	color = vec3(); //un color en funció de lopcio de menu
	//}
}
