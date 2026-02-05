#include "canevas.h"

Canevas::Canevas()
{
	// Initialisation de 3 couches
	for (int i = 0; i < 3; i++) {
		Couche coucheInitiale;
		couches += coucheInitiale;
	}
	
	couches[0].changerEtat(1); // Première couche active
	couches.setIndexCourant(0);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	*this = Canevas();
	return true;
}

bool Canevas::reinitialiserCouche(int index)
{
	couches[index].reinitialiser();
	return true;
}

bool Canevas::activerCouche(int index)
{
	if (index < 0 || index >= couches.getTaille()) return false;

	couches[couches.getIndexCourant()].changerEtat(2); //Désactivation de l'ancienne couche active

	//Activation de la nouvelle couche active
	couches[index].changerEtat(1);

	couches.setIndexCourant(index);

	if (couches[index].getNbFormes() > 0) {
		couches[index].setFormeActive(0);
	}
	else {
		couches[index].setFormeActive(-1);
	}
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
			return true;
		}
	}
	
	delete p_forme;
	return false;
}

bool Canevas::retirerForme()
{
	couches[couches.getIndexCourant()].retirer();
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
	couches[couches.getIndexCourant()].translater(deltaX, deltaY);
	return true;
}

void Canevas::modePileChange(bool mode)
{
	int ancienIndex = couches.getIndexCourant();
	int nouvelIndex = -1;

	// Nouvel index pour couche active
	if (ancienIndex != -1) {
		nouvelIndex = couches.getTaille() - 1 - ancienIndex;
	}
	
	// Vecteur invesré temp
	Vecteur<Couche> temp;
	for (int i = couches.getTaille() - 1; i >= 0; i--) {
		temp += couches[i];
	}
	
	// Réinitialistion du vecteur et ajout des valeurs
	couches.vider();
	for (int i = 0; i < temp.getTaille(); i++) {
		couches += temp[i];
	}

	// Activation bonne couche
	if (nouvelIndex != -1) {
		activerCouche(nouvelIndex);
	}
	else {
		couches.setIndexCourant(-1);
	}
}

void Canevas::afficher(ostream& s)
{
	for (int i = 0; i < couches.getTaille(); i++)
	{
		// Écriture couches
		s << "L ";
		if (couches[i].getEtat() == 1) {
			s << "a";
		}

		else if (couches[i].getEtat() == 0) {
			s << "i";
		}

		else {
			s << "x";
		}

		s << endl;

		// Écriture formes
		for(int j = 0; j < couches[i].getNbFormes(); j++) {
			s << couches[i].obtenir(j)->getInformation() << endl;
		}
	}
}

void Canevas::lire(istream& s) 
{
	// Réinitialisation du canevas
	reinitialiser();
	couches.vider();
	couches.setIndexCourant(-1);

	char type;
	// Lecture du fichier
	while (s >> type)
	{
		// Nouvelle couche
		if (type == 'L')
		{
			char etatChar;
			s >> etatChar;
			Couche nouvelle;

			// Changement d'état
			if (etatChar == 'a') {
				nouvelle.changerEtat(1);
			}

			else if (etatChar == 'x') {
				nouvelle.changerEtat(2);
			}

			else {
				nouvelle.changerEtat(0);
			}

			// Ajout de la couche
			couches += nouvelle;

			// Si active, mise à jour de l'index courant
			if (etatChar == 'a') {
				couches.setIndexCourant(couches.getTaille() - 1);
			}
		}
		// Formes
		// Rectangle
		else if (type == 'R')
		{
			int x, y, l, h;
			s >> x >> y >> l >> h;
			if (couches.getTaille() > 0)
				couches[couches.getTaille() - 1].ajouter(new Rectangle(x, y, l, h));
		}

		// Carré
		else if (type == 'K')
		{
			int x, y, c;
			s >> x >> y >> c;
			if (couches.getTaille() > 0)
				couches[couches.getTaille() - 1].ajouter(new Carre(x, y, c));
		}

		// Cercle
		else if (type == 'C')
		{
			int x, y, r;
			s >> x >> y >> r;
			if (couches.getTaille() > 0)
				couches[couches.getTaille() - 1].ajouter(new Cercle(x, y, r));
		}
	}
}

void Canevas::ajouterCoucheActive()
{
	Couche nouvelleCouche;

	// Changement état des couches
	int indexAncienneCoucheActive = getCoucheActive(); 
	couches[indexAncienneCoucheActive].changerEtat(2); 
	nouvelleCouche.changerEtat(1); 
	couches += nouvelleCouche; 

	// Mise à jour index courant
	couches.setIndexCourant(couches.getTaille() - 1); 
}

void Canevas::retirerCoucheActive()
{
	int indexCoucheActive = getCoucheActive();

	// Rien si aucune couche active
	if (indexCoucheActive == -1) {
		return;
	}

	// Suppression couche active
	for (int i = indexCoucheActive; i < couches.getTaille() - 1; i++) {
		couches[i] = couches[i + 1];
	}

	couches.setTaille(couches.getTaille() - 1);

	// Activation nouvelle couche active
	if (couches.getTaille() > 0) {
		couches.setIndexCourant(0);
		couches[couches.getIndexCourant()].changerEtat(1);
	}

	else {
		couches.setIndexCourant(-1);
	}
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
	return couches.getIndexCourant();
	return -1;
}

void Canevas::retirerFormeActive()
{
	couches[getCoucheActive()].retirer();
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

int Canevas::getIndexFormeActive()
{
	int indexCouche = getCoucheActive();
	// Vérification couche active
	if (indexCouche != -1) {
		// Vérification forme active
		if (couches[indexCouche].getNbFormes() == 0) {
			return -1;
		}

		return couches[indexCouche].getFormeActive();
	}
	return -1;
}

Forme* Canevas::getFormeActivePtr()
{
	int indexActif = getCoucheActive();
	// Vérification couche active
	if (indexActif >= 0) {
		// Vérification forme active
		int indexFormeActive = couches[indexActif].getFormeActive();
		if (indexFormeActive >= 0) {
			// Retour pointeur forme active
			return couches[indexActif].obtenir(indexFormeActive);
		}
	}
	return nullptr;
}

void Canevas::afficherDebug() {
	cout << "\n=========================================" << endl;
	cout << "             ETAT DU CANEVAS  " << endl;
	cout << "=========================================" << endl;

	int indexCoucheActive = getCoucheActive();

	for (int i = 0; i < couches.getTaille(); i++)
	{
		bool isLayerActive = (i == indexCoucheActive);

		if (isLayerActive) cout << "==> ";
		else               cout << "    ";

		cout << "[COUCHE " << i << "] ";

		int etat = couches[i].getEtat();
		if (etat == 1) {
			cout << "ACTIVE";
		}
		else if (etat == 2) {
			cout << "Inactive";
		}
		else {
			cout << "Initialisee";
		}

		cout << endl;

		int nbFormes = couches[i].getNbFormes();
		int indexFormeActive = couches[i].getFormeActive();

		if (nbFormes == 0) {
			cout << "        (Vide)" << endl;
		}
		else {
			for (int j = 0; j < nbFormes; j++) {
				cout << "        ";

				if (isLayerActive && j == indexFormeActive) {
					cout << "-> ";
				}
				else if (j == indexFormeActive) {
					cout << "* ";
				}
				else {
					cout << "   ";
				}

				cout << "[" << j << "] ";
				Forme* f = couches[i].obtenir(j);
				if (f) {
					cout << f->getInformation();
				}
				cout << endl;
			}
		}
		cout << "    --------------------------------" << endl;
	}
	cout << endl;
}