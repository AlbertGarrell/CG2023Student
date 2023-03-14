// This variables comes from the vertex shader
// They are baricentric interpolated by pixel according to the distance to every vertex
varying vec3 v_world_normal;
varying vec2 v_uv;

uniform sampler2D u_texture1;
uniform float u_option; //uniform variable que passem des del render d'aplication

void main() 
{
	// Set the ouput color per pixel
	vec4 color = texture2D(u_texture1, v_uv);
	

	gl_FragColor = vec4(1.0);
}
