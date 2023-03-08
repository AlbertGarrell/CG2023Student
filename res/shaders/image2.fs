//Pràctica 4

varying vec2 v_uv;
uniform sampler2D u_texture;
uniform float u_time;
uniform float u_option;
uniform float u_aspectRatio;
void main(){
    
	vec4 texture_color;
    vec2 v_uvs;
    float angle = 45;
    

    if(u_option == 0.0){
        int N = 30;
        float mov = sin(u_time) * N;
        v_uvs = vec2(floor(v_uv.x*mov)/mov, floor(v_uv.y*mov)/mov);

        texture_color = texture2D(u_texture, v_uvs);
    }
    else if(u_option == 1.0){
        int N = 10;
        float mov = sin(u_time)*N;
        v_uvs = vec2(mix((1-mov)*v_uv.x,v_uv.x,v_uv.x), mix(mov*v_uv.y,v_uv.y,v_uv.y));



        texture_color = texture2D(u_texture, v_uvs);
    }
    else if(u_option == 2.0){ //Dividir la pantalla en N**2 cops la imatge
        int N = 2;
        float x = fract(v_uv.x*N);
        float y = fract(v_uv.y*N);
        v_uvs = vec2(x,y);
    }
    else if(u_option == 3.0){
        vec2 v_uvs = v_uv;
        float sin_factor = sin(angle);
        float cos_factor = cos(angle);
        //v_uvs = (v_uvs - 0.5) * mat2(cos_factor, sin_factor, -sin_factor, cos_factor);
        v_uvs = vec2(v_uvs.x - 0.5) * (u_aspectRatio, v_uvs.y - 0.5) * mat2(cos_factor, sin_factor, -sin_factor, cos_factor);
        v_uvs += 0.5;
    }
    else if(u_option == 4.0){
        //float x = v_uv.x + sin(v_uv.x);
        float x = distance(v_uv.x, 0.5);
        //float y = v_uv.y + sin(v_uv.y);
        float y = distance(v_uv.y, 0.5);
        v_uvs = vec2(x,y);
    }
    else{
        v_uvs = v_uv;
    }

    texture_color = texture2D(u_texture, v_uvs);
	gl_FragColor = texture_color;
}