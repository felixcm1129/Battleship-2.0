#pragma once
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images

class Bateau
{

private:

	int height;
	int width;

	int idx = 0;

	SDL_Texture* texture_bateau[5];
	SDL_Rect position_bateau;

	int x;
	int y;



public:

	void Creation_Bateau(int, int, SDL_Renderer*);

	SDL_Rect Set_Position(int, int);

	SDL_Rect Get_Position();

	SDL_Texture* Get_Texture(int);

	void Collision();

	void Init_Deplacement(int, int);

	void Verifier_Bord();

	int Get_X();
	int Get_Y();

};

