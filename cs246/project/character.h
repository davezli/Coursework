#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include <iostream>
#include "cell.h"

class Character : public Cell {
protected:
    int hp;
    int atk;
    int def;
    bool moved;
public:
    //Methods
    virtual void print() = 0;
    int getHP();
    virtual int getATK();
    virtual int getDEF();
    void changeHP(int hp);
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    void resetMoved();
    bool hasMoved();
    bool isEnemy();
    //since we can't use casting AKA PUSSY METHOD
    /*      virtual Cell* look(Cell** layout);
          virtual int getGold();
          virtual int getMagnitude();
          virtual std::string getRace() {}
          virtual void addGold(int n) {}
          virtual void attack(Enemy* attacked) {}
          virtual void attack(Player* attacked) {}
          virtual void changeATK(int n) {}
          virtual void changeDEF(int n) {}
          virtual void moveRandom(Cell** layout) {}
          virtual void resetStats() {}
          virtual void usePotion(Potion* p) {}
    */    //Constructor
//    Character() {}
    //Destructor
//    ~Character() {}
};

#endif
