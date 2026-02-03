#include "couche.h"

Couche::Couche(int etatBase)
{
	etat = etatBase;
}

Couche :: ~Couche()
{
}

void Couche::ajouter(Forme* p_forme)
{
	formes += p_forme;
}


void Couche::retirer(int index)
{
	delete formes[index];
}


Forme* Couche::obtenir(int index)
{
	return formes[index];
}


double Couche::aire()
{
	double aire = 0;

	// Total des aires de toutes les formes
	for (int i = 0; i < formes.getTaille(); i++) {
		aire += formes[i]->aire();
	}

	return aire;
}


bool Couche::translater(int x, int y)
{
	// Translation de toutes les formes
	for (int i = 0; i < formes.getTaille(); i++) {
		formes[i]->translater(x, y);
	}

	return true;
}


bool Couche::reinitialiser()
{
	formes.vider();
	return true;
}


bool Couche::changerEtat(int nouvelEtat)
{
	etat = nouvelEtat;
	return true;
}


int Couche::getEtat()
{
	return etat;
}