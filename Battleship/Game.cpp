#include "Game.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "include/SDL.h"// sdl de base
#include "include/SDL_ttf.h" // pour écrire sur la fenêtre sdl
#include "include/SDL_mixer.h"// pour la musique
#include "include/SDL_image.h"// pour tout type d'images
#include "include/SDL_ttf.h"
#include "Demo.h"

using namespace std;

Game::Game()
{
	bateau[0].Get_Texture(0);
	bateau[1].Get_Texture(1);
	bateau[2].Get_Texture(2);
	bateau[3].Get_Texture(3);
	bateau[4].Get_Texture(4);

	for (int i = 0; i < 100; i++)
	{
		tab[i] = false;
	}

	quit = false;
	index_tab = 0;
	idx_bateau = 0;
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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
			SDL_SetRenderDrawColor(renderer,0,0,0,0);
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

void Game::update()
{
	
}


void Game::render()
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

	SDL_RenderCopy(renderer, bateau[idx_bateau].Get_Texture(idx_bateau), NULL, &bateau[idx_bateau].Get_Position());

	for (int i = 0; i < 5; i++)
	{
		if (bateau_dispo[i] == false)
		{
			SDL_RenderCopy(renderer, bateau[i].Get_Texture(i), NULL, &bateau[i].Get_Position());
		}
	}
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned!" << endl;
}

void Game::Creation_Bateau()
{
	cout << "idx : " << idx_bateau << endl;
	bateau[idx_bateau].Creation_Bateau(10, 10, renderer);
	cout << "Bateau creer" << endl;
}

void Game::Deplacement_du_Bateau()
{

	int tmp_index;

	switch (event.type) {



	case SDL_KEYDOWN:

		switch (event.key.keysym.sym) {


		case SDLK_UP:

			cout << "Up" << endl;

			bateau[idx_bateau].Set_Position(0, -58);

			index_tab += -10;

			if (bateau[idx_bateau].Get_Y() < 10)
			{
				index_tab += 10;
			}

			bateau[idx_bateau].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab[index_tab] << endl;

			tmp_index = index_tab + 10;

			if (occuper())
			{
				bateau[idx_bateau].Set_Position(0, 58);
				index_tab = tmp_index;
				cout << endl << "index_tab : " << index_tab << endl;
			}

			break;


		case SDLK_DOWN:

			cout << "Down" << endl;

			bateau[idx_bateau].Set_Position(0, 58);

			index_tab += 10;

			if (bateau[idx_bateau].Get_Y() > 532)
			{
				index_tab += -10;
			}

			bateau[idx_bateau].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab[index_tab] << endl;

			tmp_index = index_tab - 10;

			if (occuper())
			{
				bateau[idx_bateau].Set_Position(0, -58);
				index_tab = tmp_index;
				cout << endl << "index_tab : " << index_tab << endl;
			}

			break;


		case SDLK_RIGHT:

			cout << "Right" << endl;

			bateau[idx_bateau].Set_Position(78, 0);

			index_tab += 1;

			if (bateau[idx_bateau].Get_X() > 712)
			{
				index_tab += -1;
			}

			bateau[idx_bateau].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab[index_tab] << endl;


			tmp_index = index_tab - 1;

			if (occuper())
			{
				bateau[idx_bateau].Set_Position(-78, 0);
				index_tab = tmp_index;
				cout << endl << "index_tab : " << index_tab << endl;
			}

			break;



		case SDLK_LEFT:

			cout << "Left" << endl;

			bateau[idx_bateau].Set_Position(-78, 0);

			index_tab += -1;

			if (bateau[idx_bateau].Get_X() < 10)
			{
				index_tab += 1;
			}

			bateau[idx_bateau].Verifier_Bord();

			cout << endl << "index_tab : " << index_tab << endl;
			cout << "tab[" << index_tab << "] : " << tab[index_tab] << endl;

			tmp_index = index_tab + 1;

			if (occuper())
			{
				bateau[idx_bateau].Set_Position(78, 0);
				index_tab = tmp_index;
				cout << endl << "index_tab : " << index_tab << endl;
			}

			break;

		case SDLK_INSERT:

			cout << "Bateau placer" << endl;

			bateau_dispo[idx_bateau] = false;
			
			tab[index_tab] = true;

			idx_bateau++;
			
			
			
			if (idx_bateau > 4)
			{
				cout << endl << "Tout les bateaux ont ete placer!" << endl;

				quit = true;

				break;
			}

			else
			{
				cout << "idx : " << idx_bateau << endl;

				Creation_Bateau();
				render();

				index_tab = 0;
			}
			

		}

		break;

	}


}

bool Game::occuper()
{
	if (tab[index_tab] == true)
	{
		return true;
	}
	else return false;
}

bool Game::get_tab(int i)
{
	return tab[i];
}

bool Game::Quitter() 
{
	
	while (SDL_PollEvent(&event)) {

		return quit;
	}
}
