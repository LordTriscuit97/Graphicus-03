#include "couche.h"

Couche::Couche(int etatBase)
{
	etat = etatBase;
	formes.setIndexCourant(-1);
}

Couche :: ~Couche()
{
	for (int i = 0; i < formes.getTaille(); i++) {
		delete formes[i];
	}
}

Couche :: Couche(Couche& original)
{
	etat = original.etat;
	
	// Copie des formes
	for (int i = 0; i < original.formes.getTaille(); i++)
	{
		Forme* source = original.formes[i];

		// Vérification du type de forme et copie
		if (Cercle* c = dynamic_cast<Cercle*>(source)) {
			formes += new Cercle(*c);
		}

		else if (Rectangle* r = dynamic_cast<Rectangle*>(source)) {
			formes += new Rectangle(*r);
		}

		else if (Carre* k = dynamic_cast<Carre*>(source)) {
			formes += new Carre(*k);
		}
	}
}

Couche& Couche::operator=(Couche& original)
{
	// Suppression des formes existantes
	for (int i = 0; i < formes.getTaille(); i++) {
		delete formes[i];
	}
	formes.vider();

	// Copie des formes
	etat = original.etat;

	for (int i = 0; i < original.formes.getTaille(); i++)
	{
		Forme* source = original.formes[i];

		if (Cercle* c = dynamic_cast<Cercle*>(source)) {
			formes += new Cercle(*c);
		}
		else if (Rectangle* r = dynamic_cast<Rectangle*>(source)) {
			formes += new Rectangle(*r);
		}
		else if (Carre* k = dynamic_cast<Carre*>(source)) {
			formes += new Carre(*k);
		}
	}
	return *this;
}

void Couche::ajouter(Forme* p_forme)
{
	formes += p_forme;
	formes.setIndexCourant(formes.getTaille() - 1);
}

void Couche::retirer()
{
	int index = formes.getIndexCourant();

	// Vérification index valide
	if (index < 0 || index >= formes.getTaille()) {
		return;
	}

	// Suppression de la forme
	delete formes[index];

	// Décalage 
	for (int i = index; i < formes.getTaille() - 1; i++) {
		formes[i] = formes[i + 1];
	}

	formes.setTaille(formes.getTaille() - 1);

	// Index courant après suppression
	if (formes.getTaille() == 0) {
		formes.setIndexCourant(-1);
	}

	else {
		formes.setIndexCourant(0);
	}
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
	// Suppression de toutes les formes
	for (int i = 0; i < formes.getTaille(); i++) {
		delete formes[i];
	}
	formes.vider();

	etat = 0;
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

int Couche::getNbFormes()
{
	return formes.getTaille();
}

int Couche::getFormeActive()
{
	if (formes.getTaille() == 0) {
		return -1;
	}

	return formes.getIndexCourant();

}

void Couche::setFormeActive(int index)
{
	formes.setIndexCourant(index);
}

void Couche::formeSuivante() {
	++formes;
}

void Couche::formePrecedente() {
	--formes;
}

