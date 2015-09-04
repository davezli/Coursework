#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Goblin : public Enemy
{
public:
    //Methods
    void print();
    //Constructor
    Goblin(int a, int b);
    //Destructor
    ~Goblin();
};

#endif
