#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "texture.h"
#include "shader.h"



class Light
{

private:
	std::vector<Vector3> lightPos;
	std::vector<Vector3> id;
	std::vector<Vector3> is;


public:
	Light();
	void Render();
};