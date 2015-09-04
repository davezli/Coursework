#ifndef __ELF_H__
#define __ELF_H__
#include <string>
#include <iostream>
#include "player.h"
//#include "item.h"
#include "potion.h"

class Elf : public Player
{
public:
    //Methods
    void usePotion(Potion* p);
    //Constructor
    Elf(int x, int y);
    //Destructor
    ~Elf();
};

#endif
