#ifndef COUCHE_H
#define COUCHE_H
#include "vecteur.h"
#include "forme.h"

// 0 : initialisee
// 1 : active
// 2 : non active

class Couche
{
	int etat;
	Vecteur <Forme*> formes;


public:
	
	Couche(int etatBase = 0);
	~Couche();
	void ajouter(Forme* p_forme);
	void retirer(int index);
	Forme* obtenir(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	bool reinitialiser();
	bool changerEtat(int nouvelEtat);
	int getEtat();
	int getNbFormes();
};
#endif
