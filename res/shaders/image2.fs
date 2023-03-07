//Pràctica 4

varying vec2 v_uv;
uniform sampler2D u_texture;
uniform float u_time;
uniform float u_option3;
void main(){
    
	vec4 texture_color;
    vec2 v_uvs;
    

    if(u_option3 == 0.0){
        int N = 30;
        float mov = sin(u_time) * N;
        v_uvs = vec2(floor(v_uv.x*mov)/mov, floor(v_uv.y*mov)/mov);



        texture_color = texture2D(u_texture, v_uvs);
    }
    else if(u_option3 == 1.0){
        int N = 10;
        float mov = sin(u_time)*N;
        v_uvs = vec2(mix((1-mov)*v_uv.x,v_uv.x,v_uv.x), mix(mov*v_uv.y,v_uv.y,v_uv.y));



        texture_color = texture2D(u_texture, v_uvs);
    }
    else if(u_option3 == 2.0){ //Dividir la pantalla en N**2 cops la imatge
        int N = 2;
        float x = fract(v_uv.x*N);
        float y = fract(v_uv.y*N);
        v_uvs = vec2(x,y);


        texture_color = texture2D(u_texture, v_uvs);
    }
    else if(u_option3 == 3.0){
        mat4 rotation;
        float angle = sin(u_time)*1.5;
        rotation[0][0] = cos(angle);
        rotation[0][1] = -sin(angle);
        rotation[0][2] = 0;
        rotation[0][3] = 1;
        rotation[1][0] = sin(angle);
        rotation[1][1] = cos(angle);
        rotation[1][2] = 0;
        rotation[1][3] = 1;
        rotation[2][0] = 0;
        rotation[2][1] = cos(angle);
        rotation[2][2] = 1;
        rotation[2][3] = 1;
        rotation[3][0] = 1;
        rotation[3][1] = 1;
        rotation[3][2] = 1;
        rotation[3][3] = 1;

        v_uvs = v_uv;
        texture_color = texture2D(u_texture, v_uvs);
        texture_color *= rotation;
    }
    else{
        v_uvs = v_uv;

        texture_color = texture2D(u_texture, v_uvs);
    }

    //Texture_color = texture2D(u_texture, v_uvs);
	gl_FragColor = texture_color;
}