#include "application.h"
#include "mesh.h"
#include "shader.h"
#include "utils.h" 
#include "entity.h"
#include "texture.h"

Application::Application(const char* caption, int width, int height)
{
	this->window = createWindow(caption, width, height);

	int w,h;
	SDL_GetWindowSize(window,&w,&h);

	this->mouse_state = 0;
	this->time = 0.f;
	this->window_width = w;
	this->window_height = h;
	this->keystate = SDL_GetKeyboardState(nullptr);

	this->framebuffer.Resize(w, h);
}

Application::~Application()
{
}

void Application::Init(void)
{
	std::cout << "Initiating app..." << std::endl;


	shader = new Shader();
	shader = Shader::Get("/shaders/raster.vs", "/shaders/raster.fs");


	/* CARREGUEM MESH I TEXTURE LEE, INICIALITZEM ENTITY  */
	lee_mesh = new Mesh();
	bool l_mesh1 = lee_mesh->LoadOBJ("meshes/anna.obj");
	if (l_mesh1 == false) {
		printf("Error al carregar la mesh 'lee.obj'.\n");
		exit(0);
	}
	lee_texture = new Texture();
	bool l_texture = lee_texture->Load("textures/anna_color_specular.tga");
	if (l_texture == false) {
		printf("Error al carregar la texture 'lee_color_specular.tga'.\n");
		exit(0);
	}
	
	camera = new Camera();
	camera->LookAt(Vector3(0.0, 0.0, 1.0), Vector3(0.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0));
	camera->SetPerspective(45, framebuffer.width / framebuffer.height, 0.01, 500);
	//camera.SetOrthographic(-1.5, 1.5, 1.5, -1.5, -1.5, 1.5);


	lee_entity = new Entity(lee_mesh, lee_texture, camera, shader);
	lee_entity->SetModelMatrix(Vector3(0.0, -0.25, 0.0), 0.0, Vector3(1.0, 1.0, 1.0), Vector3(1.0, 1.0, 1.0));

	sLight light;
	ia = Vector3(50/255.0, 50/255.0, 50/255.0);
	light.id = Vector3(1.0);
	light.is = Vector3(0.2);
	light.lightPos = Vector3(2, 2, 2);
	
}

// Render one frame
void Application::Render(void)
{
	/*Clean Buffer*/
	/*Uniforms*/	


	shader->Enable();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	shader->SetMatrix44("u_model", lee_entity->modelMatrix);
	shader->SetMatrix44("u_viewprojection", camera->viewprojection_matrix);
	shader->SetTexture("u_texture1", lee_texture);
	lee_mesh->Render();
	glDisable(GL_DEPTH_TEST);
	shader->Disable();
	
	
	//lee_entity.Render();


}

// Called after render
void Application::Update(float seconds_elapsed)
{
	camera->SetAspectRatio((float)window_width / window_height);
	camera->UpdateProjectionMatrix();
}

//keyboard press event 
void Application::OnKeyPressed( SDL_KeyboardEvent event )
{
	// KEY CODES: https://wiki.libsdl.org/SDL2/SDL_Keycode
	switch(event.keysym.sym) {
		case SDLK_ESCAPE: // ESC key, kill the app
			exit(0);
			break;
		case SDLK_1: //Ex 3.1
			shader = Shader::Get("/shaders/quad.vs", "/shaders/quad.fs");
			option = -1.0;
			menu = 0;
			break;
		case SDLK_2: //Ex 3.2
			shader = Shader::Get("/shaders/image.vs", "/shaders/image.fs");
			option = -1.0;
			menu = 0;
			break;
		case SDLK_3: //Ex 3.3
			shader = Shader::Get("/shaders/image2.vs", "/shaders/image2.fs");
			option = -1.0;
			menu = 0;
			break;
		case SDLK_4:
			shader = Shader::Get("/shaders/raster.vs", "/shaders/raster.fs");
			option = -1.0;
			menu = 1;
			break;
		case SDLK_a: //3.1 i 3.2 a)
			option = 0.0;
			break;
		case SDLK_b: //3.1 i 3.2 b)
			option = 1.0;
			break;
		case SDLK_c: //3.1 i 3.2 c)
			option = 2.0;
			break;
		case SDLK_d:
			option = 3.0; //3.1 i 3.2 d)
			break;
		case SDLK_e:
			option = 4.0; //3.1 i 3.2 e)
			break;
		case SDLK_f:
			option = 5.0; //3.1 i 3.2 f)
			break;

		case SDLK_r: //Reiniciem i mostrem limatge normal o b� la pantalla en blanc si �s ex3.1
			option = -1.0;
			break;





		case SDLK_p: //Perspective i pintar tot
			camera->SetPerspective(45, framebuffer.width / framebuffer.height, 0.01, 500);
			menu = 1;
			break;
		case SDLK_o: //Orthografic i pintar tot
			camera->SetOrthographic(-1.5, 1.5, 1.5, -1.5, -1.5, 1.5);
			menu = 1;
			break;

		case SDLK_LEFT:
			menu = 1;
			camera->eye = camera->eye - 0.1;
			camera->UpdateViewMatrix();
			break;
		case SDLK_RIGHT:
			menu = 1;
			camera->eye = camera->eye + 0.1;
			camera->UpdateViewMatrix();
			break;
	}
}

void Application::OnMouseButtonDown( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) {

	}
}

void Application::OnMouseButtonUp( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) {

	}
}

void Application::OnMouseMove(SDL_MouseButtonEvent event)
{
	
}

void Application::OnWheel(SDL_MouseWheelEvent event)
{
	float dy = event.preciseY;

	if (dy >= 0) {
		camera->eye.z = camera->eye.z - 0.2;
	}
	else if (dy < 0) {
		camera->eye.z = camera->eye.z + 0.2;

	}
	camera->UpdateViewMatrix();
}

void Application::OnFileChanged(const char* filename)
{ 
	Shader::ReloadSingleShader(filename);
}