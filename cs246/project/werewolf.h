#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Werewolf : public Enemy
{
public:
    //Methods
    void print();
    //Constructor
    Werewolf(int a, int b);
    //Destructor
    ~Werewolf();
};

#endif
