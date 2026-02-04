#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "couche.h"

class Canevas
{
	Vecteur <Couche> couches;

public:
	Canevas();
	~Canevas();
	bool reinitialiser();
	bool reinitialiserCouche(int index);
	bool activerCouche(int index);
	bool desactiverCouche(int index);
	bool ajouterForme(Forme* p_forme);
	bool retirerForme(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	void modePileChange(bool mode);
	void afficher(ostream& s);
};
#endif
