#ifndef CENARIO_H
#define CENARIO_H

#include <SDL.h>
#include <iostream>

#include "../Camera/camera.h"
#include "../Objetos/esfera.h"
#include "../CSG/Primitives/CSGTree.h"

using namespace std;

class Cenario {
public:
	Cor background;
	Camera camera;
	//alterar para objetos apos implementar classe objeto
	vector<Esfera> objetos;
	//vector<Fontes> fontes; descomentar após a introdução de luzes

	CSGTree* tree;
	 
	Cenario(); //inicializa o cenario
	Cenario(Camera& camera); //inicializa o cenario

	void adicionarObjeto(Esfera& esfera); //trocar esfera para objeto posteriormente
	void pintarCanvas();
	void renderizarCena();

	/*CSG stuff*/

	void addTree(CSGTree *tree);
	void paintCanvas();

};

#endif