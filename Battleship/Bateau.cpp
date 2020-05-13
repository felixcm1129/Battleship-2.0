#include "Bateau.h"
#include "stdio.h"
#include "iostream"
#include "string"
using namespace std; //cout, cin

void Bateau::Creation_Bateau(int new_x, int new_y, SDL_Renderer *Renderer)
{
	position_bateau.x = new_x;

	position_bateau.y = new_y;

	position_bateau.h = 58;

	position_bateau.w = 78;

	texture_bateau[0] = IMG_LoadTexture(Renderer, "images/ShipBattleshipHull.png");

	texture_bateau[1] = IMG_LoadTexture(Renderer, "images/ShipCarrierHull.png");
	
	texture_bateau[2] = IMG_LoadTexture(Renderer, "images/ShipDestroyerHull.png");

	texture_bateau[3] = IMG_LoadTexture(Renderer, "images/ShipPatrolHull.png");

	texture_bateau[4] = IMG_LoadTexture(Renderer, "images/ShipSubMarineHull.png");
}

SDL_Rect Bateau::Set_Position(int X, int Y)
{
	position_bateau.x = position_bateau.x + X;

	position_bateau.y = position_bateau.y + Y;


	return position_bateau;
}

SDL_Rect Bateau::Get_Position()
{
	return position_bateau;
}

SDL_Texture* Bateau::Get_Texture(int id)
{
	return texture_bateau[id];
}

void Bateau::Collision()
{
	if (position_bateau.x > 790 || position_bateau.x < 0)
	{
		x = x * -1;
	}

	if (position_bateau.y > 590 || position_bateau.y < 0)
	{
		y = y * -1;
	}
}



void Bateau::Init_Deplacement(int new_x, int new_y)
{
	x = new_x;

	y = new_y;
}

void Bateau::Verifier_Bord()
{
	if (position_bateau.x > 712)
	{
		position_bateau.x = 712;
	}
	else if (position_bateau.x < 10)
	{
		position_bateau.x = 10;
	}
	
	if (position_bateau.y > 532)
	{
		position_bateau.y = 532;
	}
	else if (position_bateau.y < 10)
	{
		position_bateau.y = 10;
	}

	cout << endl << "Position x : " << position_bateau.x << endl;
	cout << "Position y : " << position_bateau.y << endl;

}

int Bateau::Get_X()
{
	return position_bateau.x;
}

int Bateau::Get_Y()
{
	return position_bateau.y;
}
