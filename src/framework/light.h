#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "texture.h"
#include "shader.h"



class Light
{

private:
	std::vector<Vector3> position;
	std::vector<Vector3> is;
	std::vector<Vector3> id;


public:
	Light();
	void Render();
};