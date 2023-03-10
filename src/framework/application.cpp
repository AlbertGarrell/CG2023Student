#include "application.h"
#include "mesh.h"
#include "shader.h"
#include "utils.h" 
//#include "entity.h"
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
	/******P4*****/
	shader = new Shader();
	quad = new Mesh();
	shader = Shader::Get("/shaders/quad.vs", "/shaders/quad.fs");
	quad->CreateQuad();

	fruites = new Texture();
	bool c_texture1 = fruites->Load("/images/fruits.png");
	if (c_texture1 == false) {
		printf("Error al carregar la texture 'fruits.png'.\n");
		exit(0);
	}

	/*  CARREGUEM MESH I TEXTURE LEE, INICIALITZEM ENTITY  */
	lee_mesh = new Mesh();
	bool l_mesh1 = lee_mesh->LoadOBJ("/meshes/lee.obj");
	if (l_mesh1 == false) {
		printf("Error al carregar la mesh 'lee.obj'.\n");
		exit(0);
	}
	lee_texture = new Texture();
	bool l_texture = lee_texture->Get("/textures/lee_color_specular.tga");
	if (l_texture == false) {
		printf("Error al carregar la texture 'lee_color_specular.tga'.\n");
		exit(0);
	}
	lee_entity = Entity(lee_mesh, lee_texture);
	//lee_entity.SetModelMatrix(Vector3(-0.5, 0.0, 0.0), 0.0, Vector3(0.0, 0.0, 0.0), Vector3(2.0, 2.0, 2.0));



	camera = Camera();
	camera.LookAt(Vector3(0, 0, 4.5), Vector3(0, 0, 0), Vector3(0, 1, 0));
	//camera.SetPerspective(45, framebuffer.width / framebuffer.height, 0.01, 500);
	camera.SetOrthographic(-1.5, 1.5, 1.5, -1.5, -1.5, 1.5);
}

// Render one frame
void Application::Render(void)
{
	/******P4*****/
	/*Clean Buffer*/
	shader->Enable();
	/*Uniforms*/
	shader->SetFloat("u_option", option); //option és la opció del menu
	//shader->SetFloat("u_option3", option3); //option és la opció del menu
	shader->SetTexture("u_texture", fruites);
	shader->SetFloat("u_time", time);
	shader->SetFloat("u_aspectRatio", this->window_width / this->window_height);
	
	//Per 3D
	shader->SetMatrix44("u_model", lee_entity.GetModelMatrix());
	shader->SetMatrix44("u_viewprojection", camera.GetViewProjectionMatrix());
	//
	

	quad->Render();
	shader->Disable();
}

// Called after render
void Application::Update(float seconds_elapsed)
{

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
			break;
		case SDLK_2: //Ex 3.2
			shader = Shader::Get("/shaders/image.vs", "/shaders/image.fs");
			option = -1.0;
			break;
		case SDLK_3: //Ex 3.3
			shader = Shader::Get("/shaders/image2.vs", "/shaders/image2.fs");
			option = -1.0;
			break;
		case SDLK_4:
			shader = Shader::Get("/shaders/raster.vs", "/shaders/raster.fs");
			option = -1.0;
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

		case SDLK_r: //Reiniciem i mostrem limatge normal o bé la pantalla en blanc si és ex3.1
			option = -1.0;
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

	// ...
}

void Application::OnFileChanged(const char* filename)
{ 
	Shader::ReloadSingleShader(filename);
}