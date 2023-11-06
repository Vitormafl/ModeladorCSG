#ifndef CGGRAY_H 
#define CSGRAY_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CSGRay {
public:
	glm::vec3 p0;
	glm::vec3 dr;

	CSGRay();
	CSGRay(glm::vec3 p0, glm::vec3 dr);
};

#endif