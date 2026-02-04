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
	// À implémenter ultérieurement
	return false;
}

bool Graphicus03::sauvegarderFichier(const char* filename) {
	ofstream fichier(filename);
	canevas.afficher(fichier);
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
	couches += Couche(2);
	
}

void Graphicus03::coucheRetirer() {
	couches.setTaille(couches.getTaille() - 1);
}


void Graphicus03::retirerForme() {
	canevas.retirerForme(0);
}


void Graphicus03::couchePremiere() {
	couches[0].changerEtat(1);
}

void Graphicus03::couchePrecedente() {
	couches.
}

void Graphicus03::coucheSuivante() {
	// À implémenter ultérieurement
}

void Graphicus03::coucheDerniere() {
	// À implémenter ultérieurement
}

void Graphicus03::formePremiere() {
	// À implémenter ultérieurement
}

void Graphicus03::formePrecedente() {
	// À implémenter ultérieurement
}

void Graphicus03::formeSuivante() {
	// À implémenter ultérieurement
}

void Graphicus03::formeDerniere() {
	// À implémenter ultérieurement
}

void Graphicus03::rafraichirAffichage() {
	sauvegarderFichier("temp.txt");
	// 1. On crée un fichier virtuel en mémoire
	ostringstream fichierVirtuel;

	// 2. On réutilise EXACTEMENT la même logique
	canevas.afficher(fichierVirtuel);

	// 3. On envoie le texte final à l'écran
	dessiner(fichierVirtuel.str().c_str());
}

