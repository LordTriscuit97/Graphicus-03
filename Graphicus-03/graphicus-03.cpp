#include "graphicus-03.h"

Graphicus03 :: Graphicus03(const char* theName) : GraphicusGUI(theName)
{
	effacerInformations();
	rafraichirAffichage();
}

Graphicus03 :: ~Graphicus03()
{
}

bool Graphicus03::ouvrirFichier(const char* filename) {
	ifstream fichier(filename);
	canevas.reinitialiser();
	nomFichierCourant = filename;
	canevas.lire(fichier);
	rafraichirAffichage();
	fichier.close();
	return true;
}

bool Graphicus03::sauvegarderFichier(const char* filename) {
	ofstream fichier(filename);
	canevas.afficher(fichier);
	nomFichierCourant = filename;
	fichier.close();
	return true;
}

void Graphicus03::coucheTranslater(int deltaX, int deltaY) {

	canevas.translater(deltaX, deltaY);
}

void Graphicus03::ajouterCercle(int x, int y, int rayon) {

	Cercle *p_cercle = new Cercle(x, y, rayon);
	canevas.ajouterForme(p_cercle);
	rafraichirAffichage();
}

void Graphicus03::ajouterRectangle(int x, int y, int long_x, int long_y) {

	Rectangle* p_rectangle = new Rectangle(x, y, long_x, long_y);
	canevas.ajouterForme(p_rectangle);
	rafraichirAffichage();
}

void Graphicus03::ajouterCarre(int x, int y, int cote) {

	Carre* p_carre = new Carre(x, y, cote);
	canevas.ajouterForme(p_carre);
	rafraichirAffichage();
}

void Graphicus03::modePileChange(bool mode) {

	canevas.modePileChange(mode);
	rafraichirAffichage();
	
}


void Graphicus03::reinitialiserCanevas() {
	canevas.reinitialiser();
}

void Graphicus03::coucheAjouter() {
	canevas.ajouterCoucheActive(); 
	rafraichirAffichage();
}

void Graphicus03::coucheRetirer() {
	canevas.retirerCoucheActive();
	rafraichirAffichage();
}


void Graphicus03::retirerForme() {
	canevas.retirerFormeActive();
	rafraichirAffichage();
}


void Graphicus03::couchePremiere() {
	canevas.activerCouchePremiere();
	rafraichirAffichage();
}

void Graphicus03::couchePrecedente() {
	canevas.activerCouchePrecedente();
	rafraichirAffichage();
}

void Graphicus03::coucheSuivante() {
	canevas.activerCoucheSuivante();
	rafraichirAffichage();
}

void Graphicus03::coucheDerniere() {
	canevas.activerCoucheDerniere(); 
	rafraichirAffichage();
}

void Graphicus03::formePremiere() {
	canevas.activerFormePremiere();
	rafraichirAffichage();
}

void Graphicus03::formePrecedente() {
	canevas.activerFormePrecedente();
	rafraichirAffichage();
}

void Graphicus03::formeSuivante() {
	canevas.activerFormeSuivante();
	rafraichirAffichage();
}

void Graphicus03::formeDerniere() {
	canevas.activerFormeDerniere();
	rafraichirAffichage();
}

void Graphicus03::rafraichirAffichage() {
	
	ostringstream fichierTemp;
	canevas.afficher(fichierTemp);
	dessiner(fichierTemp.str().c_str());
	sauvegarderFichier(nomFichierCourant.c_str());
	majInformations();
}

void Graphicus03::majInformations() {
	/*
	// Nbre de couches
	infos.nbCouches = canevas.getNbCouches();

	// Nbre de formes dans le canevas
	infos.nbFormesCanevas = canevas.getNbFormesTotal();

	// Couche active
	infos.coucheActive = canevas.getCoucheActive();

	// Aire canevas
	infos.aireCanevas = canevas.aire();

	if(infos.coucheActive >= 0) {

		// Nbre de formes dans la couche active
		infos.nbFormesCouche = canevas.getNbFormesDansCoucheActive();

		// État de la couche active
		strcpy(infos.etatCouche, "Active");

		// Aire de la couche active
		infos.aireCouche = canevas.getAireCoucheActive();

		// Forme active
		infos.formeActive = couches[infos.coucheActive].getFormeActive();

		if (infos.formeActive >= 0) {

			// Coordonnées de la forme active
			Forme* p_forme = couches[infos.coucheActive].obtenir(infos.formeActive);
			infos.coordX = p_forme->getX();
			infos.coordY = p_forme->getY();

			// Aire de la forme active
			infos.aireForme = p_forme->aire();
		}
	}
	setInformations(infos);
	*/
}