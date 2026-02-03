/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe pour une couche dans un
 *    canevas. La classe Couche gère un vecteur de pointeurs de formes
 *    géométriques en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
// kira0932 & yams3291
#include "vecteur.h"

// 0 : initialisee
// 1 : active
// 2 : non active

class Couche
{
public:
	Vecteur formes;
	Couche(int etatBase = 0);
	~Couche();
	bool ajouter(Forme* p_forme);
	Forme* retirer(int index);
	Forme* obtenir(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	bool reinitialiser();
	bool changerEtat(int nouvelEtat);
	void afficher(ostream& s);
	int getEtat();

private:
	int etat;
};

#endif
