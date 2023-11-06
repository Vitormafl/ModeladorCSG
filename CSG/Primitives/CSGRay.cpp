#include "CSGRay.h"

CSGRay::CSGRay() {}

CSGRay::CSGRay(glm::vec3 p0, glm::vec3 dr) {
	this->p0 = p0;
	this->dr = dr;
}
