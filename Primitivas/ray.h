#ifndef RAY_H
#define RAY_H

#include "ponto.h"
#include "vetor.h"

class Ray {
public:
	Ponto p0;
	Vetor dr;

	Ray();
	Ray(Ponto p0, Vetor dr);
};

#endif