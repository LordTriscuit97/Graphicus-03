#include "forme.h"

Forme::Forme(int x1, int y1)
{
    x = x1;
    y = y1;
}

Forme::~Forme()
{
}

void Forme::translater(int deltaX, int deltaY)
{
    x += deltaX;
    y += deltaY;
}

int Forme::getX() const
{
    return x;
}

int Forme::getY() const
{
    return y;
}

void Forme::setAncrage(int x1, int y1)
{
    x = x1;
    y = y1;
}
