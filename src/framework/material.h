#pragma once

#include "framework.h"
#include "mesh.h"
#include "texture.h"
#include "shader.h"



class Material
{

	typedef struct sLight { //Afegir una posició i un color intensity per diffuse i specular
		std::vector<Vector3> kd;
	} sLight;

private:
	Texture* texture;
	Shader* shader;
	
	std::vector<Vector3> kd;
	std::vector<Vector3> ks;

public:
	Material();
	void Render();
	void Enable();
	void Disable();
};