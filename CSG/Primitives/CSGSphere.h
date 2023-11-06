#ifndef	CSGSPHERE_H
#define CSGSPHERE_H

#include "Primitive.h"

class CSGSphere : public Primitive{
public:

	glm::vec3 center;
	float radius;
	Cor cor;

	vector<EdgeHits> checkIntersection(CSGRay r, vector<GeometricOperation> vGOP);

	CSGSphere(glm::vec3 center, float radius, Cor cor);
};

#endif