#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int x, int y, int l, int h) : Forme(x, y)
{
	largeur = l;
	hauteur = h;
}


Rectangle :: ~Rectangle()
{
}


double Rectangle::aire()
{
	return largeur * hauteur;
}


void Rectangle::afficher(ostream& s)
{
	s << "Rectangle(x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << endl;
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