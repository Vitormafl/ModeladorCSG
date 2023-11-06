#include "ray.h"

Ray::Ray() {
	this->p0 = Ponto();
	this->dr = Vetor();
}

Ray::Ray(Ponto p0, Vetor dr) {
	this->p0 = p0;
	this->dr = dr;
}