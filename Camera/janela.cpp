#include "janela.h"

Janela::Janela() {
	this->wJanela = 0;
	this->hJanela = 0;
	this->nLinhas = 0;
	this->nColunas = 0;
	this->centro = Ponto();
}

Janela::Janela(int wJanela, int hJanela, int nLinhas, int nColunas, Ponto centro) {
	this->wJanela = wJanela;
	this->hJanela = hJanela;
	this->nLinhas = nLinhas;
	this->nColunas = nColunas;
	this->centro = centro;
}

