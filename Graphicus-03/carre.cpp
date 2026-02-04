#include "carre.h"
#include <iostream>

using namespace std;

Carre::Carre(int x, int y, int c) : Forme(x, y)
{
	cote = c;
	pos_x = x;
	pos_y = y;
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

string Carre::getInformation()
{
	string info = "K " + to_string(pos_x) + " " + to_string(pos_y) + " " + to_string(cote);
	return info;
}