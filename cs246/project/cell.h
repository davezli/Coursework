#ifndef __CELL_H__
#define __CELL_H__
#include <string>
#include <iostream>

class Enemy;
class Player;
class Potion;
class Cell {
protected:
    //(x,y) coordinates of the cell in the chambers
    int x;
    int y;
    //(lx,ly) coordinates of the cell in the levels (only for player)
    int lx;
    int ly;
    //type of cell (Default is floortile)
    std::string type;
public:
    //Methods
    virtual void print();
    //returns x,y,cx,cy coordinates and type:
    int getX();
    int getY();
    int getLX();
    int getLY();
    std::string getType();
    //sets the x,y,cs,cy coordinates and type
    void setX(int nx);
    void setY(int ny);
    void setLX(int nx);
    void setLY(int ny);
    void setType(std::string s);
    //checks the type of the cell (can be one of character, item, floor tile, passage, stairs)
    bool isItem();
    bool isFloorTile();
    bool isPassage();
    bool isStairs();
    //since we can't use casting AKA PUSSY METHOD
    virtual Cell* look(Cell*** layout, int width, int height);
    virtual void lookPotion(Cell*** layout, int width, int height) {}
    virtual bool hasMoved();
    virtual bool isDoor();
    virtual bool isDragonDead();
    virtual bool isEnemy();
    virtual bool isPotion();
    virtual std::string getAction() {
        return "";
    }
//     virtual int getChamberNum();
    virtual int getATK();
    virtual int getAmount();
    virtual int getDEF();
    virtual int getGold();
    virtual int getHP();
    virtual int getMagnitude();
    virtual std::string getRace();
    virtual void addGold(int n) {}
    virtual void attackEnemy(Enemy* attacked) {}
    virtual void attackPlayer(Player* attacked) {}
    virtual void changeATK(int n) {}
    virtual void changeDEF(int n) {}
    virtual void changeHP(int hp) {}
    //   virtual void setChamberNum(int ch){}
    virtual void moveDown() {}
    virtual void moveEnemy(Cell*** layout, int dx, int dy) {}
    virtual void moveLeft() {}
    virtual void moveRandom(Cell*** layout, int width, int height) {}
    virtual void moveRight() {}
    virtual void moveUp() {}
    virtual void resetStats() {}
    virtual void resetMoved() {}
    virtual void setDoor() {}
    virtual void setAction(std::string s) {}
    virtual void usePotion(Potion* p) {}
    static void usedBA() {}
    static void usedBD() {}
    static void usedPH() {}
    static void usedRH() {}
    static void usedWA() {}
    static void usedWD() {}

    virtual int getdATK() {
        return 0;
    }
    //Constructors
    Cell();
    Cell(int nx, int ny);
    //Destructor
    ~Cell();
    //Operator
    Cell &operator=(const Cell &other);
};

#endif
