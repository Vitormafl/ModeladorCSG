#ifndef ESFERA_H
#define ESFERA_H

#include <cmath>
#include <iostream>

#include "../Primitivas/cor.h"
#include "../Primitivas/ray.h"
#include "../Algebra/algebra.h"

using namespace std;

struct indiceObjetoDistancia {
	bool acerto;
	double distancia;
	Ponto intersecao;
};

class Esfera {
public:
	double raio;
	Cor cor;
	Ponto centro;

	Esfera();
	Esfera(double raio, Cor cor, Ponto centro);

	indiceObjetoDistancia verificarIntersecção(Ray raio);
};


#endif