#include "esfera.h"

Esfera::Esfera(){
	this->raio = 0.0;
	this->cor = Cor();
	this->centro = Ponto();
};

Esfera::Esfera(double raio, Cor cor, Ponto centro) {
	this->raio = raio;
	this->cor = cor;
	this->centro = centro;
};

indiceObjetoDistancia Esfera::verificarIntersecção(Ray raio) {
	
	Vetor w = Vetor(raio.p0.x - this->centro.x, raio.p0.y - this->centro.y, raio.p0.y - this->centro.z);

	double a = produtoEscalar(raio.dr, raio.dr);
	double b = 2 * produtoEscalar(w, raio.dr);
	double c = produtoEscalar(w, w) - this->raio * this->raio;

	double delta = b * b - 4 * a * c;
	if (delta < 0)
	{	
		indiceObjetoDistancia semIntersecao = {false, 0.0, Ponto()};
		return semIntersecao;
	}
	else {
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);

		double t = (t1 < t2) ? t1 : t2;

		if (t1 < 0) {
			if (t2 < 0) {
				indiceObjetoDistancia semIntersecao = { false, 0.0, Ponto() };
				return semIntersecao;
			}
			else {
				t = t2;
			}
		}


		raio.dr.normalizado();
		raio.dr.multEscalar(t);
		double distColisao = sqrt(raio.dr.x * raio.dr.x + raio.dr.y * raio.dr.y + raio.dr.z * raio.dr.z);

		Ponto pontoIntersecao = Ponto(raio.p0.x + raio.dr.x * t, raio.p0.y + raio.dr.y * t, raio.p0.z + raio.dr.z * t);

		return indiceObjetoDistancia{true, distColisao, pontoIntersecao};
	}
};