#include "vetor.h"

Vetor::Vetor() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
};

Vetor::Vetor(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

void Vetor::normalizado(){
	double comprimento = sqrt(this->x* this->x + this->y* this->y + this->z* this->z);

	if (comprimento != 0) {
		this->x /= comprimento;
		this->y /= comprimento;
		this->z /= comprimento;
	}
};

void Vetor::multEscalar(double escalar) {
	this->x *= escalar;
	this->y *= escalar;
	this->z *= escalar;
};