#include "ponto.h"

Ponto::Ponto() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
};

Ponto::Ponto(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}