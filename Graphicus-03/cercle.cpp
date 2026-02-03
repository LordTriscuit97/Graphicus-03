#include "cercle.h"
#include <iostream>

using namespace std;

Cercle::Cercle(int x, int y, int r) : Forme(x, y)
{
	rayon = r;
}


Cercle :: ~Cercle()
{
}


double Cercle::aire()
{
	return rayon * 3.1416;
}


void Cercle::afficher(ostream& s)
{
	s << "Cercle(x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon << ", aire=" << aire() << ")" << endl;
}


int Cercle::getRayon()
{
	return rayon;
}


void Cercle::setRayon(int r)
{
	if (r > 0) {
		rayon = r;
	}
}