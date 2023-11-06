#ifndef JANELA_H
#define JANELA_H

#include <vector>

#include "../Primitivas/ponto.h"
#include "../Primitivas/vetor.h"
#include "../Primitivas/cor.h"

using namespace std;

class Janela {
public:
	int wJanela, hJanela, nLinhas, nColunas;
	Ponto centro;
	vector<vector<Cor>> canvas;

	Janela();
	Janela(int wJanela, int hJanela, int nLinhas, int nColunas, Ponto centro);
};

#endif