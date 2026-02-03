#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "forme.h"


class Rectangle :public Forme {
public:
	Rectangle(int x = 0, int y = 0, int l = 1, int h = 1);
	~Rectangle();
	double aire();
	void afficher(ostream& s);
	int getLargeur();
	int getHauteur();
	void setLargeur(int l);
	void setHauteur(int h);

protected:
	int largeur;
	int hauteur;

};
#endif
