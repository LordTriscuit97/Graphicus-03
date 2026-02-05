#ifndef COUCHE_H
#define COUCHE_H
#include "vecteur.h"
#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"

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
	Couche(Couche& original);
	Couche& operator=(Couche& original);
	void ajouter(Forme* p_forme);
	void retirer();
	Forme* obtenir(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	bool reinitialiser();
	bool changerEtat(int nouvelEtat);
	int getEtat();
	int getNbFormes();
	int getFormeActive();
	void setFormeActive(int index);
	void formeSuivante();
	void formePrecedente();

};
#endif
