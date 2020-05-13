#include "Curseur.h"
#include "stdio.h"
#include "iostream"
#include "string"
using namespace std; //cout, cin

void Curseur::Creation_Curseur(int new_x, int new_y, SDL_Renderer* Renderer)
{
	position_curseur.x = new_x;

	position_curseur.y = new_y;

	position_curseur.h = 58;

	position_curseur.w = 78;

	texture_curseur[0] = IMG_LoadTexture(Renderer, "images/blanc.png");

	for (int i = 1; i < 101; i++)
	{
		texture_curseur[i] = IMG_LoadTexture(Renderer, "images/noir.png");
	}
	
	for (int i = 101; i < 201; i++)
	{
		texture_curseur[i] = IMG_LoadTexture(Renderer, "images/rouge.png");
	}

}

SDL_Rect Curseur::Set_Position(int X, int Y)
{
	position_curseur.x = position_curseur.x + X;

	position_curseur.y = position_curseur.y + Y;


	return position_curseur;
}

SDL_Rect Curseur::Get_Position()
{
	return position_curseur;
}

SDL_Texture* Curseur::Get_Texture(int id)
{
	return texture_curseur[id];
}

void Curseur::Collision()
{
	if (position_curseur.x > 790 || position_curseur.x < 0)
	{
		x = x * -1;
	}

	if (position_curseur.y > 590 || position_curseur.y < 0)
	{
		y = y * -1;
	}
}



void Curseur::Init_Deplacement(int new_x, int new_y)
{
	x = new_x;

	y = new_y;
}

void Curseur::Verifier_Bord()
{
	if (position_curseur.x > 712)
	{
		position_curseur.x = 712;
	}
	else if (position_curseur.x < 10)
	{
		position_curseur.x = 10;
	}

	if (position_curseur.y > 532)
	{
		position_curseur.y = 532;
	}
	else if (position_curseur.y < 10)
	{
		position_curseur.y = 10;
	}

	cout << endl << "Position x : " << position_curseur.x << endl;
	cout << "Position y : " << position_curseur.y << endl;

}

int Curseur::Get_X()
{
	return position_curseur.x;
}

int Curseur::Get_Y()
{
	return position_curseur.y;
}