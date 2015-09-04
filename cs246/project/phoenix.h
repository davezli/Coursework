#ifndef __PHOENIX_H__
#define __PHOENIX_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Phoenix : public Enemy
{
public:
    //Methods
    void print();
    //Constructor
    Phoenix(int a, int b);
    //Destructor
    ~Phoenix();
};

#endif
