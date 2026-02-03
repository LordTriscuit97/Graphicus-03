// kira0932 & yams3291
/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe Canevas. La classe gère un
 *    tableau de couches en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
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
	void afficher(ostream& s);

private:
	Couche couches[MAX_COUCHES];
};

#endif
