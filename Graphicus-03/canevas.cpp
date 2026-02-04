#include "canevas.h"

Canevas::Canevas()
{
	// Initialisation de 3 couches
	for (int i = 0; i < 3; i++) {
		Couche coucheInitiale;
		couches += coucheInitiale;
	}
	
	couches[0].changerEtat(1); // Première couche active
}


Canevas::~Canevas()
{
}


bool Canevas::reinitialiser()
{
	// Réinitialisation + état initial pour toutes les couches
	for (int i = 0; i < couches.getTaille(); i++) {
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
	for (int i = 0; i < couches.getTaille(); i++) {
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
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == 1) {
			couches[i].ajouter(p_forme);
		}
	}
	return true;
}


bool Canevas::retirerForme(int index)
{
	// Retrait de la forme dans la couche active
	for (int i = 0; i < couches.getTaille(); i++) {
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
	for (int i = 0; i < couches.getTaille(); i++) {
		aire += couches[i].aire();
	}
	return aire;
}


bool Canevas::translater(int deltaX, int deltaY)
{
	// Translation de la couche active
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == 1) {
			couches[i].translater(deltaX, deltaY);
		}
	}
	return true;
}

void Canevas::modePileChange(bool mode)
{
	if (mode) {
		//Inversion des couches
		Vecteur <Couche> couchesInverses;
		for (int i = couches.getTaille() - 1; i >= 0; i--) {
			couchesInverses += couches[i];
		}
		couches = couchesInverses;
	}
}


void Canevas::afficher(ostream& s)
{
	for (int i = 0; i < couches.getTaille(); i++)
	{
		// 1. Écriture de l'entête de la couche (L)
		s << "L ";
		if (couches[i].getEtat() == 1) s << "a";
		else if (couches[i].getEtat() == 0) s << "i";
		else s << "x";
		s << endl;

		for(int j = 0; j < couches[i].getNbFormes(); j++) {
			s << couches[i].obtenir(j)->getInformation() << endl;
		}
		
	}
}

