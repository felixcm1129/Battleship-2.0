#pragma once
#include "stdio.h"
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images

#include "Bateau.h"

class Game
{
public : 
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	bool Quitter();
	void update();
	void render();
	void clean();

	void Creation_Bateau();

	void Deplacement_du_Bateau();

	bool occuper();

	bool get_tab(int i);


private:

	Bateau bateau[5];
	SDL_Rect position_du_bateau;

	int idx_bateau;

	int index_tab;

	bool tab[100];
	bool quit = false;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* background;
	SDL_Rect positionback;

	SDL_Event event;

	bool bateau_dispo[5] = { true };

};

