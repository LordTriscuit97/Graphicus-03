#include "carre.h"
#include <iostream>

using namespace std;

Carre::Carre(int x, int y, int c) : Forme(x, y)
{
	cote = c;
}


Carre :: ~Carre()
{
}


double Carre::aire()
{
	return cote * cote;
}



int Carre::getCote()
{
	return cote;
}


void Carre::setCote(int c)
{
	if (c > 0) {
		cote = c;
	}
}