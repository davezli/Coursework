#ifndef __TROLL_H__
#define __TROLL_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Troll : public Enemy
{
public:
    //Methods
    void print();
    //Constructor
    Troll(int a, int b);
    //Destructor
    ~Troll();
};

#endif
