#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"

class Cercle : public Forme {

public:
	Cercle(int x = 0, int y = 0, int r = 1);
	~Cercle();
	double aire();
	void afficher(ostream& s);
	int getRayon();
	void setRayon(int r);

private:
	int rayon;
};
#endif

