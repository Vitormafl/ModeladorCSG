#ifndef CSGTREE_h
#define CSGTREE_h

#include "CSGSphere.h"
#include "GeometricOperation.h"

class CSGTree {
public:
	CSGTree* leftChildTree;
	CSGTree* rightChildTree;
	booleanOperation operation;
	bool isPrimitive;
	Primitive *primitive;
	GeometricOperation* geoOP;

	CSGTree(CSGTree* leftChildTree, CSGTree* rightChildTree, booleanOperation operation);
	CSGTree(CSGTree* leftChildTree, GeometricOperation* geoOP, booleanOperation operation);
	CSGTree(Primitive* primitive);

	std::vector<EdgeHits> checkIntersection(CSGRay r);
};

#endif

