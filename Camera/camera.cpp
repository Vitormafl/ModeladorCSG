#include "camera.h"

Camera::Camera(){
	this->olho = Ponto();
	this->janela = Janela();
	this->dJanela = 500;
	this->canvasConfigurado = false;
};

Camera::Camera(Ponto olho, Janela janela,double dJanela) {
	this->olho = olho;
	this->janela = janela;
	this->dJanela = dJanela;
	this->canvasConfigurado = false;

	this->setCanvas();
};

void Camera::setCanvas() {

	if (this->canvasConfigurado == true) {
		return;
	}

	vector<Cor> vetorVazioCor;
	Cor corVazia = Cor();
	this->canvasConfigurado = true;

	for (int j = 0; j < this->janela.nColunas; j++) {
		vetorVazioCor.push_back(corVazia);
	}
	for (int i = 0; i < this->janela.nLinhas; i++) {
		this->janela.canvas.push_back(vetorVazioCor);
	}

}
