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

void Canevas::lire(istream& s) {
	char type;

	// BOUCLE DE LECTURE : Tant qu'il y a des lettres à lire dans le fichier
	while (s >> type)
	{
		// CAS 1 : C'est une COUCHE
		if (type == 'L')
		{
			char etat;
			s >> etat; // On lit 'a', 'i' ou 'x'

			// On crée la couche
			activerCouche(0); // Astuce: on se remet sur la 0 pour ne pas perdre le fil
			ajouterCoucheActive();  // On ajoute une nouvelle couche à la fin

			// On récupère l'index de cette nouvelle couche (la dernière)
			int index = couches.getTaille() - 1;

			// On applique l'état lu dans le fichier
			if (etat == 'a') couches[index].changerEtat(1);
			else if (etat == 'i') couches[index].changerEtat(0);
			else couches[index].changerEtat(2);
		}
		// CAS 2 : C'est un RECTANGLE
		else if (type == 'R')
		{
			int x, y, l, h;
			s >> x >> y >> l >> h; // On aspire les 4 chiffres
			ajouterForme(new Rectangle(x, y, l, h)); // On l'ajoute à la couche active
		}
		// CAS 3 : C'est un CARRÉ
		else if (type == 'K')
		{
			int x, y, c;
			s >> x >> y >> c;
			ajouterForme(new Carre(x, y, c));
		}
		// CAS 4 : C'est un CERCLE
		else if (type == 'C')
		{
			int x, y, r;
			s >> x >> y >> r;
			ajouterForme(new Cercle(x, y, r));
		}
	}
}

void Canevas::ajouterCoucheActive()
{
	Couche nouvelleCouche;
	couches += nouvelleCouche;
}

void Canevas::retirerCoucheActive()
{
	couches.setTaille(couches.getTaille() - 1);
}																


int Canevas::getNbCouches()
{
	return couches.getTaille();
}

int Canevas::getNbFormesTotal()
{
	int totalFormes = 0;
	for (int i = 0; i < couches.getTaille(); i++) {
		totalFormes += couches[i].getNbFormes();
	}
	return totalFormes;
}

int Canevas::getCoucheActive()
{
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == 1) {
			return i;
		}
	}
	return -1; // Aucune couche active
}

void Canevas::retirerFormeActive()
{
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == 1) {
			int indexFormeActive = couches[i].getFormeActive();
			couches[i].retirer(indexFormeActive);
		}
	}
}

void Canevas::activerCouchePremiere()
{
	activerCouche(0);
}

void Canevas::activerCouchePrecedente()
{
	int indexActif = getCoucheActive();
	if (indexActif > 0) {
		activerCouche(indexActif - 1);
	}
}

void Canevas::activerCoucheSuivante()
{
	int indexActif = getCoucheActive();
	if (indexActif < couches.getTaille() - 1) {
		activerCouche(indexActif + 1);
	}
}

void Canevas::activerCoucheDerniere()
{
	activerCouche(couches.getTaille() - 1);
}

void Canevas::activerFormePremiere()
{
	couches[getCoucheActive()].setFormeActive(0);
}

void Canevas::activerFormePrecedente()
{
	couches[getCoucheActive()].formePrecedente();
}

void Canevas::activerFormeSuivante()
{
	couches[getCoucheActive()].formeSuivante();
}

void Canevas::activerFormeDerniere()
{
	int nbFormes = couches[getCoucheActive()].getNbFormes();
	couches[getCoucheActive()].setFormeActive(nbFormes - 1);
}

int Canevas::getNbFormesDansCoucheActive()
{
	int indexActif = getCoucheActive();
	if (indexActif >= 0) {
		return couches[indexActif].getNbFormes();
	}
	return 0;
}

int Canevas::getAireCoucheActive()
{
	int indexActif = getCoucheActive();
	if (indexActif >= 0) {
		return couches[indexActif].aire();
	}
	return 0;
}


