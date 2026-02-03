// kira0932 & yams3291
/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    couche.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/
#include <iostream>
#include "couche.h"

Couche::Couche(int etatBase)
{
	// Si on veut initialiser une couche avec un autre état
	etat = etatBase;
}

Couche :: ~Couche()
{
}

bool Couche::ajouter(Forme* p_forme)
{
	return formes.ajouter(p_forme);
}


Forme* Couche::retirer(int index)
{
	// Gestion index non valide
	if (index < 0 || index > formes.getTaille()) {
		return NULL;
	}

	return formes.retirer(index);
}


Forme* Couche::obtenir(int index)
{
	// Gestion index non valide
	if (index < 0 || index > formes.getTaille()) {
		return NULL;
	}

	return formes.tableau[index];
}


double Couche::aire()
{
	double aire = 0;

	// Total des aires de toutes les formes
	for (int i = 0; i < formes.getTaille(); i++) {
		aire += formes.tableau[i]->aire();
	}

	return aire;
}


bool Couche::translater(int x, int y)
{
	// Translation de toutes les formes
	for (int i = 0; i < formes.getTaille(); i++) {
		formes.tableau[i]->translater(x, y);
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
	// Gestion état non valide
	if (nouvelEtat < 0 || nouvelEtat > 2) {
		return false;
	}

	etat = nouvelEtat;
	return true;
}


void Couche::afficher(ostream& s)
{
	// Affichage état
	switch (etat) {
	case 0:
		s << "État : initialisee" << endl;
		break;

	case 1:
		s << "État : active" << endl;
		break;

	case 2:
		s << "État : non active" << endl;
		break;
	}

	// Affichage des formes
	for (int i = 0; i < formes.getTaille(); i++) {
		formes.tableau[i]->afficher(s);
	}
}

int Couche::getEtat()
{
	return etat;
}
