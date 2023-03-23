#include "material.h"

Material::Material() {
}

void Material::Render() {

}


void Material::Enable(const sUniformData& uniformData) {
	this->shader->Enable();


	this->shader->SetVector3("u_Ka", this->ka);
	this->shader->SetVector3("u_Kd", this->kd);
	this->shader->SetVector3("u_Ks", this->kd);

	this->shader->SetFloat("u_shininess", this->shininess);

	this->shader->SetTexture("u_texture", this->texture);
	//this->shader->SetTexture("u_texture_normals", this->MaterialNormals);

	//this->shader->SetFloat("u_apply_texture",);

	this->shader->SetMatrix44("u_model", uniformData.modelMatrix);
	this->shader->SetMatrix44("u_viewprojection", uniformData.viewProjection);
	this->shader->SetVector3("u_ia", uniformData.ia);
	this->shader->SetVector3("u_id", uniformData.light.id);
	this->shader->SetVector3("u_is", uniformData.light.is);
	this->shader->SetVector3("u_light_position", uniformData.light.lightPos);
	//this->shader->SetVector3("u_eye_position", uniformData.EyePosition);



}
void Material::Disable() {
	this->shader->Disable();
}


