#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class booleanOperation { NONE, UNION, INTERSECTION, AMINUSB, BMINUSA, SCALING, TRANSLATION };

class GeometricOperation {
public:
	glm::vec3 attributes;
	booleanOperation operationType;

	GeometricOperation(glm::vec3 attributes, booleanOperation operationType) {
		this->attributes = attributes;
		this->operationType = operationType;
	};
};