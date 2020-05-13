#pragma once
#include "stdio.h"
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images
#include "Game.h"
#include "Curseur.h"

class Demo
{
public:
	Demo();
	~Demo();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	bool Quitter();
	void render();
	void clean();

	void Deplacement_du_Curseur();

	void Creation_Curseur();

	bool occuper();

	void verifier_tab(Game *g);

private:

	Curseur curseur[201];
	SDL_Rect position_du_curseur;

	int index_tab;

	int idx_noir;
	int idx_rouge;

	int idx_curseur;

	Game* game;

	bool tab_game[100];
	bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* background;
	SDL_Rect positionback;

	SDL_Event event;

};

