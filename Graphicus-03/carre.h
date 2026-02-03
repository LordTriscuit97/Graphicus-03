#ifndef CARRE_H
#define CARRE_H
#include "forme.h"

class Carre : public Forme {

public:
	Carre(int x = 0, int y = 0, int c = 1);
	virtual ~Carre();
	double aire() override;
	int getCote();
	void setCote(int c);

private:
	int cote;
};
#endif

