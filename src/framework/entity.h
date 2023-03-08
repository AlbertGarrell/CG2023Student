#pragma once

#include "framework.h"
#include "mesh.h"
#include "image.h"

enum class eRenderMode {
	POINTCLOUD, //punts
	WIREFRAME, //Malla P2
	TRIANGLES, //PlainColor
	TRIANGLES_INTERPOLATED //coord. baricentriques
};



class Entity
{
	typedef struct sTriangleInfo {
		Vector2 uv0;
		Vector2 uv1;
		Vector2 uv2;
		Vector3 v0;
		Vector3 v1;
		Vector3 v2;
		Color c0;
		Color c1;
		Color c2;
		Image* texture;
	} sTriangleInfo;

private:
	Mesh* mesh;
	Matrix44 modelMatrix;
	Image* texture;
	bool btext = false;
	eRenderMode mode = eRenderMode::TRIANGLES_INTERPOLATED;

public:
	Entity();
	Entity(Mesh* mesh);
	Entity(Mesh* mesh, Image* texture);
	std::vector<Vector3> vertexs;
	std::vector<Vector2> uvs;

	void Render(Image* framebuffer, Camera* camera, const Color& c, FloatImage* zBuffer, bool oculsions);
	void SetModelMatrix(Vector3 transalte, float angle, Vector3 rotate, Vector3 scale);
	void UpdateEntity(float seconds_elapsed, Vector3 rotate, Vector3 scale, Vector3 translate);

	Matrix44 GetModelMatrix();

	//Funcions per accedir al bool de textures i modificar-lo
	bool GetBoolTexture();
	void SetBoolTexture(bool btext);
	//Funcions per accedir al mode de pintar i canviar-lo
	eRenderMode GetPaintMode();
	void SetPaintMode(eRenderMode mode);


};