#include <iostream>
#include "Cena/cenario.h"

#include "CSG/Primitives/CSGTree.h"

using namespace std;

int main(int agrc, char* argv[]) {

	double dJanela = 100;
	int wJanela = 720;
	int hJanela = 720;
	int nLinhas = 720;
	int nColunas = 720;

	Camera camera = Camera(Ponto(0,0,0), Janela(wJanela, hJanela, nLinhas, nColunas, Ponto(0,0,-dJanela)), dJanela);
	
	CSGSphere s1(glm::vec3(0, 0, -25), 15, Cor(255, 0, 0));
	CSGSphere s2(glm::vec3(0, 0, -45), 15, Cor(200, 255, 0));
	CSGSphere s3(glm::vec3(0, 0, -60), 15, Cor(100, 255, 0));

	CSGTree t1(&s1);
	CSGTree t2(&s2);
	CSGTree t3(&t1, &t2, booleanOperation::UNION);
	Cenario scene(camera);

	CSGTree t4(&s3);
	CSGTree t5(&t3, &t4, booleanOperation::UNION);

	Esfera e1(20, Cor(255, 255, 0), Ponto(0, 0, -25));
	scene.adicionarObjeto(e1);

	scene.addTree(&t3);
	
	CSGRay ray(glm::vec3(0,0,0), glm::vec3(0,0,-1));
	
	vector<EdgeHits> vt = t5.checkIntersection(ray);
	
	cout << vt.size() << endl;



	//scene.paintCanvas();
	//scene.renderizarCena();

	return 0;
}