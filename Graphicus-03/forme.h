#ifndef FORME_H
#define FORME_H

#include <iostream>

using namespace std;

class Forme
{
public:
    Forme(int x = 0, int y = 0);
    virtual ~Forme();
    void translater(int deltaX, int deltaY);
    int getX() const;
    int getY() const;
    void setAncrage(int x, int y);
    virtual double aire() = 0;
protected:
    int x;
    int y;
};

#endif
