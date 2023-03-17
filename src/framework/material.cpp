#include "material.h"

Material::Material() {
}

void Material::Render() {

}


void Material::Enable() {
	this->shader->Enable();
}
void Material::Disable() {
	this->shader->Disable();
}
