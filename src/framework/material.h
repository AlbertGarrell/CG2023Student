#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "texture.h"
#include "shader.h"



class Material
{

private:
	Matrix44 modelMatrix;
	Mesh* mesh;
	Texture* texture;
	Camera* camera;
	Shader* shader;

public:
	Material();
	void Render();
};