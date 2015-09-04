#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <fstream>
#include <iostream>
#include "level.h"
#include "player.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"
#include "level.h"

class Game
{
public:
    Level * level;
    Level ** levelArr;
    char ** fileCharArr;
    int currentLevel;
    bool isDefault;
    Player* p;
    std::string playertype;
    Game(char * fileName, bool isDefaultFile, std::string race);
    void print();
    void generate();
    void tick();
    void newLevel(char * fileName);
    ~Game();
};

#endif

