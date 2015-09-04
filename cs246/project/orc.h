#ifndef __ORC_H__
#define __ORC_H__
#include <string>
#include <iostream>
#include "player.h"
//#include "item.h"
//#include "potion.h"

class Orc : public Player
{
public:
    //Methods
    int getGold();
    //Constructor
    Orc(int x, int y);
    //Destructor
    ~Orc();
};

#endif
