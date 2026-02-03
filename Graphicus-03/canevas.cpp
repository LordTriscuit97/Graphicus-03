// kira0932 & yams3291
/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    canevas.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
#include "iostream"
using namespace std;

Canevas::Canevas()
{
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	// Réinitialisation + état initial pour toutes les couches
	for (int i = 0; i < MAX_COUCHES; i++) {
		couches[i].reinitialiser();
		couches[i].changerEtat(0);
	}
	return true;
}

bool Canevas::reinitialiserCouche(int index)
{
	// Réinitialisation d'une couche
	couches[index].reinitialiser();
	return true;
}

bool Canevas::activerCouche(int index)
{
	// Désactivation de l'ancienne couche active
	for (int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].getEtat() == 1) {
			desactiverCouche(i);
		}
	}

	//Activation de la nouvelle couche active
	couches[index].changerEtat(1);
	return true;
}

bool Canevas::desactiverCouche(int index)
{
	// Changement d'état vers désactivé
	couches[index].changerEtat(2);
	return true;
}

bool Canevas::ajouterForme(Forme* p_forme)
{
	// Gestion pointeur null
	if (p_forme == NULL) {
		return false;
	}

	// Ajout de la forme dans la couche active
	for (int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].getEtat() == 1) {
			couches[i].ajouter(p_forme);
		}
	}
	return true;
}

bool Canevas::retirerForme(int index)
{
	// Retrait de la forme dans la couche active
	for (int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].getEtat() == 1) {
			couches[i].retirer(index);
		}
	}
	return true;
}

double Canevas::aire()
{
	double aire = 0;

	// Addition des aires pour toutes les couches
	for (int i = 0; i < MAX_COUCHES; i++) {
		aire += couches[i].aire();
	}
	return aire;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	// Translation de la couche active
	for (int i = 0; i < MAX_COUCHES; i++) {
		if (couches[i].getEtat() == 1) {
			couches[i].translater(deltaX, deltaY);
		}
	}
	return true;
}

void Canevas::afficher(ostream& s)
{
	// Affichage de toutes les couches
	for (int i = 0; i < MAX_COUCHES; i++) {
		s << "----- Couche " << i << " -----" << endl;
		couches[i].afficher(s);
	}
}
