#ifndef __DWARF_H__
#define __DWARF_H__
#include <string>
#include <iostream>
#include "player.h"
//#include "item.h"
//#include "potion.h"

class Dwarf : public Player
{
public:
    //Methods
    int getGold();
    //Constructor
    Dwarf(int x, int y);
    //Destructor
    ~Dwarf();
};

#endif
