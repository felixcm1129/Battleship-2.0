#include "stdio.h"
#include "iostream"
#include "string"
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images
#include "Game.h"
#include "Demo.h"

using namespace std; //cout, cin

Game* game = nullptr;

Demo* demo = nullptr;


int main(int argc, char* argv[])
{
	game = new Game();
	demo = new Demo();

	bool tab[100] = { false };

	game->init("BattleShip", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	game->Creation_Bateau();
	
	while (!(game->Quitter()))
	{
		game->Deplacement_du_Bateau();
		game->render();
		SDL_Delay(95);
	}

	demo->init("Demo de Jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	demo->Creation_Curseur();
	demo->verifier_tab(game); //recoit le tab de bool de Game.cpp
	
	while (!(demo->Quitter()))
	{
		demo->Deplacement_du_Curseur();
		demo->render();
		SDL_Delay(95);
	}

	game->clean();
	demo->clean();

	return 0;
}