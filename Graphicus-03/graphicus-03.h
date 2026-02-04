#ifndef GRAPHICUS03_H
#define GRAPHICUS03_H
#include <fstream>
#include <sstream>
#include "graphicusGUI.h"
#include "canevas.h"
#include "couche.h"
#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include "vecteur.h"


class Graphicus03 : public GraphicusGUI
{
	Canevas canevas;
	Vecteur<Couche> couches;

	public:
		Graphicus03 (const char *theName = nullptr);
		~Graphicus03();
		bool ouvrirFichier(const char*);
		bool sauvegarderFichier(const char*);
		void coucheTranslater(int deltaX, int deltaY);
		void ajouterCercle(int x, int y, int rayon);
		void ajouterRectangle(int x, int y, int long_x, int long_y);
		void ajouterCarre(int x, int y, int cote);
		void modePileChange(bool mode);
		void rafraichirAffichage();

	public slots:
		// Menu Canevas
		void reinitialiserCanevas();
		void coucheAjouter();
		void coucheRetirer();
		// Menu Formes
		void retirerForme();
		// Menu navigation
		void couchePremiere();
		void couchePrecedente();
		void coucheSuivante();
		void coucheDerniere();
		void formePremiere();
		void formePrecedente();
		void formeSuivante();
		void formeDerniere();

};
#endif // GRAPHICUS03_H