#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
#include "enemy.h"
#include "item.h"
#include "potion.h"
#include <math.h>
#include "character.h"

class Enemy;
class Potion;
class Player : public Character
{
protected:
    int gold;
    int datk;
    int ddef;
    std::string action;
    int chamberNum;
    std::string posType;
    bool inChamber;
public:
    //Methods
    std::string getRace();
    std::string getPosType();
    void setPosType(std::string s);
    std::string getAction();
    void setAction(std::string s);
    int getChamberNum();
    void setChamberNum(int n);
    bool isInChamber();
    void setInChamber(bool b);
    void addGold(int n);
    int getdATK();
    // overridden move methods
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    virtual int getGold();
    virtual void usePotion(Potion* p);
    void changeATK(int n);
    void changeDEF(int n);
    void attackEnemy(Enemy* attacked);
    void resetStats();
    void lookPotion(Cell*** layout, int width, int height);
    // Overridden methods
    int getATK();
    int getDEF();
    void print();
    Player();
    ~Player();
    //Operator
    Player &operator=(const Player &other);
};

#endif
