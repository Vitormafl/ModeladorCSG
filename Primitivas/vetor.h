#ifndef VETOR_H
#define VETOR_H

#include <cmath>

using namespace std;

class Vetor {
public:
	double x, y, z;

	Vetor();

	Vetor(double x, double y, double z);

	void normalizado();
	void multEscalar(double escalar);
};

#endif