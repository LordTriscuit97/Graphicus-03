#ifndef VECTEURTEST_H
#define VECTEURTEST_H
using namespace std;
#include <iostream>

template <typename type>
class Vecteur
{
	int capacite;
	int taille;
	type* tableau;
	int indexCourant;

	void doublerCapacite();

public:
	Vecteur();
	~Vecteur();
	void vider();
	bool estVide();
	int getTaille();
	int getCapacite();

	type& operator[](int index);
	Vecteur& operator+=(type item);
	Vecteur& operator++();
	Vecteur& operator--();


	friend ostream& operator<<(ostream& s, const Vecteur<type>& item)
	{
		//Affichage de tous les items du vecteur
		for (int i = 0; i < item.taille; i++) {
			s << item.tableau[i] << endl;
		}
		return s;
	}


	friend istream& operator>>(istream& s, Vecteur<type>& item)
	{
		//Lecture des items dans le vecteur
		for (int i = 0; i < item.taille; i++) {
			s >> item.tableau[i];
		}
		return s;
	}
};
#include "vecteur.cpp"
#endif

