#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "CSGRay.h"
#include "GeometricOperation.h"
#include "../Primitivas/cor.h"
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

class Primitive;

struct EdgeHits {
	glm::vec3 HitPoint;
	float hitDistance;
	bool isEntry;
	Cor cor;
};

class Primitive {
public:

	Cor cor;

	virtual vector<EdgeHits> checkIntersection(CSGRay r, vector<GeometricOperation> vGOP);
};

#endif