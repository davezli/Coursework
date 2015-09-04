#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Vampire : public Enemy
{
public:
    //Methods
    void print();
    //Constructor
    Vampire(int a, int b);
    //Destructor
    ~Vampire();
};

#endif
