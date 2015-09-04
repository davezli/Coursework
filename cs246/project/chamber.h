#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include "floor.h"
#include "cell.h"
#include "stairs.h"
#include "player.h"
#include "vampire.h"
#include "werewolf.h"
#include "goblin.h"
#include "troll.h"
#include "phoenix.h"
#include "merchant.h"
#include "dragon.h"
#include <iostream>
#include "human.h"
#include "gold.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"

class Chamber : public Floor
{
public:
    Cell ***layout;
    Chamber();
    Chamber(int w, int h);
    Chamber(char ** c, Player * p, int shiftw, int shifth, int w, int h);
    ~Chamber();
    void updateDisplay();
    void print();
    void tick();
    void spawn();
    Chamber &operator=(const Chamber &other);
};
#endif
