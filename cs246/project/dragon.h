#ifndef __DRAGON_H__
#define __DRAGON_H__
#include <string>
#include <iostream>
#include "enemy.h"

class DragonGold;
class Dragon : public Enemy
{
protected:
    DragonGold * dg;
public:
    //Methods
    void print();
    DragonGold * getDragonGold();
    //Constructor
    Dragon(int a, int b);
    Dragon(int a, int b, DragonGold * dg);
    //Destructor
    ~Dragon();
};

#endif
