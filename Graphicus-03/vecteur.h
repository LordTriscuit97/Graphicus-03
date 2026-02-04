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
	void setTaille(int nouvelleTaille);

	type& operator[](int index);
	Vecteur& operator+=(type item);
	Vecteur& operator++();
	Vecteur& operator--();
	Vecteur& operator=(const Vecteur& orginal);
	Vecteur(const Vecteur& original);

	
	


	template <typename U>
	friend ostream& operator<< (std::ostream & s, const Vecteur<U>&item);

	template <typename U>
	friend istream& operator>> (istream& s, Vecteur<type>& item);
};
#include "vecteur.cpp"
#endif

