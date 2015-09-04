#ifndef __HUMAN_H__
#define __HUMAN_H__
#include <string>
#include <iostream>
#include "player.h"
//#include "item.h"
//#include "potion.h"

class Human : public Player
{
public:
    //Constructor
    Human(int a, int b);
    //Destructor
    ~Human();
};

#endif
