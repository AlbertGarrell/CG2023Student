#pragma once

#include "framework.h"
#include "mesh.h"
#include "texture.h"
#include "shader.h"
#include "application.h"


struct sLight { //Afegir una posició i un color intensity per diffuse i specular
	Vector3 lightPos;
	Vector3 id;
	Vector3 is;
};

struct sUniformData {
	//float ApplyTexture;
	//int nLights;
	std::vector<sLight> lights;
	sLight light;
	Matrix44 modelMatrix;
	Matrix44 viewProjection;
	Vector3 position;
	Vector3 ia; //Ambient Light Intensity
};

class Material
{

public:
	Texture* texture;
	Shader* shader;	
	Vector3 kd;
	Vector3 ks;
	Vector3 ka; //Serà la global
	float shininess;



	Material();
	void Render();
	void Enable(const sUniformData& uniformData);
	void Disable();
};
