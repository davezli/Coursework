#include "cell.h"

using namespace std;

void Cell::print()
{
    cout<<'.';
}

int Cell:: getX() {
    return x;
}

int Cell:: getY() {
    return y;
}
int Cell:: getLX() {
    return lx;
}

int Cell:: getLY() {
    return ly;
}
void Cell:: setX(int nx)
{
    x = nx;
}

void Cell:: setY(int ny)
{
    y = ny;
}
void Cell:: setLX(int nx)
{
    lx = nx;
}

void Cell:: setLY(int ny)
{
    ly = ny;
}
void Cell:: setType(string s)
{
    type = s;
}
string Cell:: getType()
{
    return type;
}
bool Cell:: isItem()
{
    return (type == "gold" || type == "dragongold" || type == "potion");
}

bool Cell:: isFloorTile()
{
    return (type == "floortile");
}

bool Cell:: isPassage()
{
    return (type == "passage");
}

bool Cell:: isStairs()
{
    return (type == "stairs");
}

Cell:: Cell()
{
    type = "floortile";
}

Cell:: Cell(int nx, int ny)
{
    x = nx;
    y = ny;
    type = "floortile";
}
Cell:: ~Cell() {}

Cell & Cell:: operator=(const Cell &other)
{
    x = other.x;
    y = other.y;
    type = other.type;
    return *this;
}

// Overridden methods
Cell * Cell:: look(Cell*** layout, int width, int height)
{
    return this;
}
bool Cell:: hasMoved()
{
    return false;
}
bool Cell::isDoor()
{
    return false;
}
bool Cell::isDragonDead()
{
    return false;
}
bool Cell::isEnemy()
{
    return false;
}
bool Cell::isPotion()
{
    return false;
}
int Cell::getATK()
{
    return -1;
}
int Cell::getAmount()
{
    return -1;
}
int Cell::getDEF()
{
    return -1;
}
/*
int Cell::getChamberNum()
{
  return -1;
}
*/
int Cell::getGold()
{
    return -1;
}
int Cell::getHP()
{
    return -1;
}
int Cell::getMagnitude()
{
    return -1;
}
string Cell::getRace()
{
    return "default";
}

