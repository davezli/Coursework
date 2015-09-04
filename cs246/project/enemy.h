#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <string>
#include <iostream>
#include "character.h"
#include <cstdlib>
#include "player.h"
#include <cmath>

class Player;
class Enemy : public Character
{
protected:
    static bool merchantHostile;
public:
    //Methods
    void attackPlayer(Player *attacked);
    static void merchantAttacked();
    Cell* look(Cell*** layout, int width, int height);
    void moveEnemy(Cell*** layout, int dx, int dy);
    virtual void moveRandom(Cell*** layout, int width, int height);
    std::string getRace();
    // Overridden methods
    int getATK();
    int getDEF();
    bool checkMHostile();
    void print() {}
    //Constructor
    Enemy();
    ~Enemy();
};

#endif
