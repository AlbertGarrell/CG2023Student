#include "entity.h"

Entity::Entity() {
}

Entity::Entity(Mesh* mesh) {

	this->mesh = mesh;
	this->modelMatrix = Matrix44();
	//this->mode = eRenderMode::WIREFRAME;
}

Entity::Entity(Mesh* mesh, Texture* texture, Camera* camera, Shader* shader) {

	this->mesh = mesh;
	this->modelMatrix = Matrix44();
	this->texture = texture;
	this->camera = camera;
	this->shader = shader;

}

/*
void Entity::Render(sUniformData uniformData) {
	uniformData.modelMatrix = this->modelMatrix;
	this->material->Enable(uniformData);
	this->mesh->Render();
	this->material->Disable();
}
*/

void Entity::Render() {
	//this->shader = Shader::Get("/shaders/raster.vs", "/shaders/raster.fs");
	//this->shader->Enable();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	this->shader->SetMatrix44("u_model", this->modelMatrix);
	this->shader->SetMatrix44("u_viewprojection", camera->GetViewProjectionMatrix());
	this->shader->SetTexture("u_texture1", this->texture);
	this->mesh->Render();
	glDisable(GL_DEPTH_TEST);
	//this->shader->Disable();
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




