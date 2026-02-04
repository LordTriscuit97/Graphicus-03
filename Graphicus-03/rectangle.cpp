#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int x, int y, int l, int h) : Forme(x, y)
{
	largeur = l;
	hauteur = h;
	pos_x = x;
	pos_y = y;
}


Rectangle :: ~Rectangle()
{
}


double Rectangle::aire()
{
	return largeur * hauteur;
}



int Rectangle::getLargeur()
{
	return largeur;
}


int Rectangle::getHauteur()
{
	return hauteur;
}


void Rectangle::setLargeur(int l)
{
	if (l > 0) {
		largeur = l;
	}
}


void Rectangle::setHauteur(int h)
{
	if (h > 0) {
		hauteur = h;
	}
}

string Rectangle::getInformation()
{
	string info = "R " + to_string(pos_x) + " " + to_string(pos_y) + " " + to_string(largeur) + " " + to_string(hauteur);
	return info;
}