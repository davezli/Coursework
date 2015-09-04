#ifndef __LEVEL_H__
#define __LEVEL_H__
#include "floor.h"
#include "chamber.h"
#include "player.h"
#include <cstdlib>
#include <fstream>
#include "human.h"
#include "elf.h"
#include "orc.h"
#include "dwarf.h"
#include "potion.h"
#include "gold.h"
#include "werewolf.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "phoenix.h"
#include "merchant.h"
#include "passage.h"

class Level : public Floor
{
protected:
    Player* p;
public:
    Level() : p(NULL), c1(NULL), c2(NULL), c3(NULL), c4(NULL), c5(NULL) {}
    Level(std::ifstream& file, Player* pl); // Contructor, default file
    Level(Player * pl, char ** ch); // constructor, read in from a file
    ~Level();
    Chamber * c1;
    Chamber * c2;
    Chamber * c3;
    Chamber * c4;
    Chamber * c5;
    Player * getPlayer();
    void updatePlayer();
    void print(); // Prints out the representing 2-D array
    void tick(); // Runs through one iteration of the level
    void spawn(); // sets up the initial display and layouts
    bool canPlayerMove(int dx, int dy); // Checks to see if the player can move in a certain direction
    Potion* canPlayerUse(int dx, int dy); // Checks to see if the player can use a potion in a certain direction
    Enemy* canPlayerAttack(int dx, int dy); // Checks to see if the the player can attack an enemy in a certain direction
    void removePotion(Potion* pot);
    void movePlayer(int dx, int dy); // Moves the player in the specified direction
};

#endif
