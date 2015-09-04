#ifndef __DRAGONGOLD_H__
#define __DRAGONGOLD_H__
#include <string>
#include <iostream>
#include "item.h"
#include "dragon.h"

class DragonGold : public Item
{
protected:
    Dragon * d;
    bool dragonDead;
    int amount;
public:
    //Methods
    int getAmount();
    void killDragon();
    bool isDragonDead();
    Dragon * getDragon();
    void setDragon(Dragon * dr);
    //Constructors
    DragonGold(int a, int b);
    //Destructor
    ~DragonGold();
};

#endif
