#include "Demo.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images
#include "include/SDL_ttf.h"

using namespace std;

Demo::Demo()
{
	curseur[0].Get_Texture(0);

	for (int i = 1; i < 101; i++)
	{
		curseur[i].Get_Texture(i);
	}
	for (int i = 101; i < 201; i++)
	{
		curseur[i].Get_Texture(i);
	}

	for (int i = 0; i < 100; i++)
	{
		tab_game[i] = false;
	}

	quit = false;
	index_tab = 0;

	idx_curseur = 0;

	idx_noir = 1;
	idx_rouge = 101;
	
}

Demo::~Demo()
{
}

void Demo::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsytems Initialised!...." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Window created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			cout << "Renderer created" << endl;
		}

		//loader les images
		background = IMG_LoadTexture(renderer, "images/fond.png");
		if (background == NULL)
		{
			cout << "Erreur d'initialisation de mon image" << SDL_GetError() << endl;
			system("pause");
		}


		quit = false;
	}
	else
	{
		quit = true;
	}
}

void Demo::render()
{
	int x1;
	int x2;
	int y1;
	int y2;

	positionback.x = 0;
	positionback.y = 0;
	positionback.w = 800;
	positionback.h = 600;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, background, NULL, &positionback);
	//horizontale
	x1 = 10;
	x2 = 790;
	y1 = 10;
	y2 = 10;
	for (int i = 0; i < 11; i++)
	{
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

		y1 += 58;
		y2 += 58;
	}
	//verticale
	x1 = 10;
	x2 = 10;
	y1 = 10;
	y2 = 590;
	for (int i = 0; i < 11; i++)
	{
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

		x1 += 78;
		x2 += 78;
	}

	SDL_RenderCopy(renderer, curseur[0].Get_Texture(0), NULL, &curseur[0].Get_Position());

	for (int i = 1; i < 201; i++)
	{
		SDL_RenderCopy(renderer, curseur[i].Get_Texture(i), NULL, &curseur[i].Get_Position());
	}

	SDL_RenderPresent(renderer);

}

void Demo::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Demo Cleaned!" << endl;
}

void Demo::Creation_Curseur()
{
	if (idx_curseur > 0)
	{
		curseur[idx_curseur].Creation_Curseur(curseur[0].Get_X(), curseur[0].Get_Y(), renderer);
	}
	else curseur[idx_curseur].Creation_Curseur(10, 10, renderer);
	
}

void Demo::Deplacement_du_Curseur()
{
	switch (event.type) {



	case SDL_KEYDOWN:

		switch (event.key.keysym.sym) {


		case SDLK_UP:

			cout << "Up" << endl;

			curseur[0].Set_Position(0, -58);

			index_tab += -10;

			if (curseur[0].Get_Y() < 10)
			{
				index_tab += 10;
			}

			curseur[0].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab_game[index_tab] << endl;

			break;


		case SDLK_DOWN:

			cout << "Down" << endl;

			curseur[0].Set_Position(0, 58);

			index_tab += 10;

			if (curseur[0].Get_Y() > 532)
			{
				index_tab += -10;
			}

			curseur[0].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab_game[index_tab] << endl;

			break;


		case SDLK_RIGHT:

			cout << "Right" << endl;

			curseur[0].Set_Position(78, 0);

			index_tab += 1;

			if (curseur[0].Get_X() > 712)
			{
				index_tab += -1;
			}

			curseur[0].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab_game[index_tab] << endl;

			break;



		case SDLK_LEFT:

			cout << "Left" << endl;

			curseur[0].Set_Position(-78, 0);

			index_tab += -1;

			if (curseur[0].Get_X() < 10)
			{
				index_tab += 1;
			}

			curseur[0].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab_game[index_tab] << endl;

			break;

		case SDLK_INSERT:

			if (occuper())
			{
				cout << "Toucher!" << endl;
				idx_curseur = idx_rouge;
				cout << "idx_curseur : " << idx_curseur << endl;
				Creation_Curseur();
				idx_rouge++;
				cout << "idx_rouge : " << idx_rouge << endl;
			}
			else
			{
				cout << "Rater!" << endl;
				idx_curseur = idx_noir;
				cout << "idx_curseur : " << idx_curseur << endl;
				Creation_Curseur();
				idx_noir++;
				cout << "idx_noir : " << idx_noir << endl;
			}
			render();
			idx_curseur = 0;
		}

		break;

	}


}

bool Demo::occuper()
{
	if (tab_game[index_tab] == true)
	{
		return true;
	}
	else return false;
}

void Demo::verifier_tab(Game *g)
{
	game = g;

	for (int i = 0; i < 100; i++)
	{
		tab_game[i] = game->get_tab(i);
	}
}

bool Demo::Quitter() {

	while (SDL_PollEvent(&event)) {

		return quit;
	}
}
