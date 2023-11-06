#include "cenario.h"

Cenario::Cenario(){
	this->camera = Camera();
	this->background = Cor();
}

Cenario::Cenario(Camera& camera) {
	this->camera = camera;
	this->background = Cor(100, 100, 100);
}

void Cenario::adicionarObjeto(Esfera&  esfera) {
	this->objetos.push_back(esfera);
};

void Cenario::pintarCanvas(){
	double dx = ((double)this->camera.janela.wJanela) / (double)this->camera.janela.nColunas;
	double dy = ((double)this->camera.janela.hJanela) / (double)this->camera.janela.nLinhas;
	double x, y;
	Vetor dr;

	for (int l = 0; l < this->camera.janela.nLinhas; l++) {
		y = (this->camera.janela.hJanela / 2.0) - dy / 2 - dy * l;
		for (int c = 0; c < this->camera.janela.nColunas; c++) {
			x = -(this->camera.janela.wJanela >> 1) + (dx * (c + 0.5));
			dr = Vetor(x, y, -this->camera.dJanela);
			Ray raio = Ray(this->camera.olho, dr);

			indiceObjetoDistancia colisaoMaisProxima, colisaoCandidata;

			int indiceObjeto;
			int vetorDeObjetos = this->objetos.size();

			for (int i = 0; i < vetorDeObjetos; i++) {
				if (i == 0) {
					colisaoMaisProxima = this->objetos[0].verificarIntersecção(raio);
					indiceObjeto = 0;
				}

				colisaoCandidata = this->objetos[i].verificarIntersecção(raio);

				if (colisaoCandidata.distancia < colisaoMaisProxima.distancia && colisaoCandidata.acerto == true) {
					colisaoMaisProxima = colisaoCandidata;
					indiceObjeto = i;
				}
			}


			if (colisaoMaisProxima.acerto == true) {
				this->camera.janela.canvas[l][c] = objetos[indiceObjeto].cor;
			}
			else {
				this->camera.janela.canvas[l][c] = this->background;
			}
		}
	}
};

void Cenario::renderizarCena() {
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log("Não foi possível inicializar o SDL! SDL_Error: %s", SDL_GetError());
		return;
	}

	SDL_Window* window = SDL_CreateWindow(
		"CG I - Raycaster",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		this->camera.janela.nColunas,
		this->camera.janela.nLinhas,
		SDL_WINDOW_SHOWN
	);
	
	cout << this->camera.janela.nColunas << std::endl;

	if (!window) {
		SDL_Log("Criação da janela falhou! SDL_Error: %s", SDL_GetError());
		SDL_Quit();
		return;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		SDL_Log("Criação do renderer falhou! SDL_Error: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return;
	}

	bool isRunning = true;
	SDL_Event event;

	

	while (isRunning) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderClear(renderer);

		for (int x = 0; x < this->camera.janela.nColunas; x++) {
			for (int y = 0; y < this->camera.janela.nLinhas; y++) {
				this->camera.janela.canvas[x][y].r;
				SDL_SetRenderDrawColor(
					renderer,
					this->camera.janela.canvas[x][y].r,
					this->camera.janela.canvas[x][y].g,
					this->camera.janela.canvas[x][y].b,
					255
				);
				SDL_RenderDrawPoint(renderer, y, x);
			}
		}
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return;
};

void Cenario::addTree(CSGTree* tree) {
	this->tree = tree;
}

void Cenario::paintCanvas() {
	double dx = ((double)this->camera.janela.wJanela) / (double)this->camera.janela.nColunas;
	double dy = ((double)this->camera.janela.hJanela) / (double)this->camera.janela.nLinhas;
	double x, y;
	glm::vec3 dr;

	for (int l = 0; l < this->camera.janela.nLinhas; l++) {
		y = (this->camera.janela.hJanela / 2.0) - dy / 2 - dy * l;
		for (int c = 0; c < this->camera.janela.nColunas; c++) {
			x = -(this->camera.janela.wJanela >> 1) + (dx * (c + 0.5));
			dr = glm::vec3(x, y, -this->camera.dJanela);
			CSGRay ray = CSGRay(glm::vec3(0,0,0), dr);
			
			std::vector<EdgeHits> rayHits = this->tree->checkIntersection(ray);
			
			if (rayHits.size() == 0) {
				this->camera.janela.canvas[l][c] = this->background;
			}
			else {
				this->camera.janela.canvas[l][c] = rayHits[0].cor;
			}
		}
	}
};