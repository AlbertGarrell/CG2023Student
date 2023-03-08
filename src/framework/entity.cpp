#include "entity.h"

Entity::Entity() {
}

Entity::Entity(Mesh* mesh) {

	this->mesh = mesh;
	this->modelMatrix = Matrix44();
	this->mode = eRenderMode::WIREFRAME;
}

Entity::Entity(Mesh* mesh, Texture* texture) {

	this->mesh = mesh;
	this->modelMatrix = Matrix44();
	this->texture = texture;
	this->mode = eRenderMode::TRIANGLES_INTERPOLATED;
	this->btext = true;
}

Matrix44 Entity::GetModelMatrix() {
	return this->modelMatrix;
}

Texture* Entity::GetTexture() {
	return this->texture;
}

bool Entity::GetBoolTexture() {
	return this->btext;
}
void Entity::SetBoolTexture(bool btext) {
	this->btext = btext;
}
eRenderMode Entity::GetPaintMode() {
	return this->mode;
}
void Entity::SetPaintMode(eRenderMode mode) {
	this->mode = mode;
}


void Entity::Render(Image* framebuffer, Camera* camera, const Color& c, FloatImage* zBuffer, bool oclusion) {

}

void Entity::SetModelMatrix(Vector3 translate, float angle, Vector3 rotate, Vector3 scale) {

	Vector3 vrot = rotate;
	this->modelMatrix.Translate(translate.x, translate.y, translate.z);
	this->modelMatrix.Rotate(angle, vrot);
	this->modelMatrix.Scale(scale.x, scale.y, scale.z);
}

void Entity::UpdateEntity(float seconds_elapsed, Vector3 rotate, Vector3 scale, Vector3 translate) {
	this->modelMatrix.RotateLocal(seconds_elapsed, rotate);
	this->modelMatrix.ScaleLocal(scale.x, scale.y, scale.z);
	this->modelMatrix.TranslateLocal(translate.x, translate.y, translate.z);
}




