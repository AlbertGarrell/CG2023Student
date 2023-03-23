#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "texture.h"
#include "shader.h"
#include "material.h"


class Entity
{
public:
	//Atributs
	Matrix44 modelMatrix;
	Mesh* mesh;
	//Material* material;

		//extra
	Texture* texture;
	Camera* camera;
	Shader* shader;

	//Mètodes
	Entity();
	Entity(Mesh* mesh);
	Entity(Mesh* mesh, Texture* texture, Camera* camera, Shader* shader);
	std::vector<Vector3> vertexs;
	std::vector<Vector2> uvs;

	void Render();
	//void Render(sUniformData uniformData);

	//void Render(Image* framebuffer, Camera* camera, const Color& c, FloatImage* zBuffer, bool oculsions, Shader* shader);
	void SetModelMatrix(Vector3 transalte, float angle, Vector3 rotate, Vector3 scale);
	void UpdateEntity(float seconds_elapsed, Vector3 rotate, Vector3 scale, Vector3 translate);

	Matrix44 GetModelMatrix();
	Texture* GetTexture();

};