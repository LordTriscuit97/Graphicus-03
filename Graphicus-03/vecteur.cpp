#include <iostream>
using namespace std;

template <typename type>
Vecteur<type>::Vecteur()
{
	capacite = 1;
	taille = 0;
	tableau = new type[capacite];
}


template <typename type>
Vecteur<type>::~Vecteur()
{
	vider();
	delete[] tableau;
}


template <typename type>
void Vecteur<type>::doublerCapacite()
{
	//Pointeur temp et création d'un tableau 2x plus grand
	type* nouveauTableau = new type[capacite * 2];

	//Transfet des données
	for (int i = 0; i < capacite; i++) {
		nouveauTableau[i] = tableau[i];
	}

	//Libérer l'espace
	delete[] tableau;

	//Mise à jour de l'adresse et de la capacité
	tableau = nouveauTableau;
	capacite *= 2;
}


template <typename type>
void Vecteur<type>::vider()
{
	// Supprimer les pointeurs des formes
	delete[] tableau;

	// Assignation des nouvelles valeurs de taille et capacité
	taille = 0;
	capacite = 1;

	// Rétablir un nouveau petit tableau
	tableau = new type[1];
}


template <typename type>
bool Vecteur<type>::estVide() {
	if (taille == 0) {
		return true;
	}

	return false;
}


template <typename type>
int Vecteur<type>::getTaille() {
	return taille;
}


template <typename type>
int Vecteur<type>::getCapacite() {
	return capacite;
}


template <typename type>
type& Vecteur<type>::operator[](int index)
{
	return tableau[index];
}


template <typename type>
Vecteur<type>& Vecteur<type>::operator+=(type item)
{
	//Vérification de la capacité
	if (taille >= capacite) {
		doublerCapacite();
	}

	//Ajout de l'item
	tableau[taille] = item;
	taille++;
	return *this;
}


template <typename type>
Vecteur<type>& Vecteur<type>::operator++()
{
	//Incrémentation de l'index courant
	if (indexCourant < taille - 1) {
		indexCourant++;
	}
	return *this;
}


template <typename type>
Vecteur<type>& Vecteur<type>::operator--()
{
	//Décrémentation de l'index courant
	if (indexCourant > 0) {
		indexCourant--;
	}
	return *this;
}