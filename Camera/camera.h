#ifndef CAMERA_H
#define CAMERA_H

#include "janela.h"
#include <vector>

using namespace std;
 
class Camera {
public:
	Ponto olho;
	Janela janela;
	double dJanela;
	bool canvasConfigurado;

	Camera();
	Camera(Ponto olho, Janela janela, double dJanela);

	void setCanvas();
};

#endif