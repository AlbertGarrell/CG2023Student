//Pràctica 4
//vs es vertex shader

//vermell resta
//blau multi/dividr
//verd utilitzar un altra component

varying vec2 v_uv;

void main()
{	
	// Remember the UV's range [0.0, 1.0]
	v_uv = gl_MultiTexCoord0.xy;

	gl_Position = gl_Vertex;
}