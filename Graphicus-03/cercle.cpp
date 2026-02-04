#include "cercle.h"
#include <iostream>

using namespace std;

Cercle::Cercle(int x, int y, int r) : Forme(x, y)
{
	rayon = r;
	pos_x = x;
	pos_y = y;
}


Cercle :: ~Cercle()
{
}


double Cercle::aire()
{
	return rayon * 3.1416;
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

string Cercle::getInformation()
{
	string info = "C " + to_string(pos_x) + " " + to_string(pos_y) + " " + to_string(rayon);
	return info;
}