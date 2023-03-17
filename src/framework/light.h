#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "texture.h"
#include "shader.h"



class Light
{

private:
	Matrix44 modelMatrix;
	Mesh* mesh;
	Texture* texture;
	Camera* camera;
	Shader* shader;

public:
	Light();
	void Render();
};