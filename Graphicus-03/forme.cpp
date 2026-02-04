#include "forme.h"

Forme::Forme(int x1, int y1)
{
    pos_x = x1;
    pos_y = y1;
}

Forme::~Forme()
{
}

void Forme::translater(int deltaX, int deltaY)
{
    pos_x += deltaX;
    pos_y += deltaY;
}

int Forme::getX() const
{
    return pos_x;
}

int Forme::getY() const
{
    return pos_y;
}

void Forme::setAncrage(int x1, int y1)
{
    pos_x = x1;
    pos_y = y1;
}
