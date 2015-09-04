#include "enemy.h"
#include <sstream>

using namespace std;

bool Enemy::merchantHostile = false;

void Enemy::attackPlayer(Player *attacked) {
    int n = rand() % 2;
    if(n == 0) {
        int dmg = ceil( ((double)100/ (double)(100+attacked->getDEF()) ) * getATK());
        string dmgs;
        ostringstream temp;
        temp << dmg;
        dmgs = temp.str();
        attacked->setAction(attacked->getAction() + ". " +  getType() + " attacked, and did " + dmgs + " damage");
        attacked->changeHP(-dmg);
    }
    if(n == 1) {
        attacked->setAction(attacked->getAction() + ". " + getType() + " attacked, but it missed" );
    }
}

Cell * Enemy::look(Cell*** layout, int width, int height) {
    for(int i = max(getY()-1, 0); i <=  min(getY()+1,height-1); i++) {
        for(int j = max(getX()-1,0); j <= min(getX()+1,width-1); j++) {
            if(layout[i][j] != NULL)
            {
                if(layout[i][j]->getType() == "human"||layout[i][j]->getType() == "elf"||
                        layout[i][j]->getType() == "dwarf"||layout[i][j]->getType() == "orc")
                    return layout[i][j];
            }
        }
    }
    return NULL;
}

void Enemy::moveEnemy(Cell*** layout, int dx, int dy) {
    int newX = getX() + dx;
    int newY = getY() + dy;
    Cell * c; // Temporary destination pointer
    c = layout[newY][newX];
    layout[newY][newX] = layout[getY()][getX()]; // Assign the destination to point at the player
    layout[getY()][getX()] = c; // Assign the old location to point at whatever was at the new destination
//  layout[newY][newX]->setX(newX);
//  layout[newY][newX]->setY(newY);
//cout << layout[newY][newX]->getType();
//print(); cout << "(" << getX() <<  "," << getY() << ")" << " -> " << "(" << newX  <<  "," << newY << ")" ;
}

void Enemy::moveRandom(Cell*** layout, int width, int height) {
    int myX = getX();
    int myY = getY();
    int leftX = myX-1;
    int rightX = myX+1;
    int upY = myY-1;
    int downY = myY+1;
    int n = rand() % 8;
    string directions[8] = {"no","so","ea","we","ne","nw","se","sw"};
    if(leftX < 0) { // cant move west
        directions[3] = "";
        directions[5] = "";
        directions[7] = "";
    }
    if(upY < 0) { // cant move north
        directions[0] = "";
        directions[4] = "";
        directions[5] = "";
    }
    if(rightX > width - 1) { // cant move east
        directions[2] = "";
        directions[4] = "";
        directions[6] = "";
    }
    if(downY > height - 1) { // cant move south
        directions[1] = "";
        directions[6] = "";
        directions[7] = "";
    }
    //Checks if is NULL:
    if(directions[0] == "no" && (layout[upY][myX] == NULL)) directions[0] = "";
    if(directions[1] == "so" && (layout[downY][myX] == NULL)) directions[1] = "";
    if(directions[2] == "ea" && (layout[myY][rightX] == NULL)) directions[2] = "";
    if(directions[3] == "we" && (layout[myY][leftX] == NULL)) directions[3] = "";
    if(directions[4] == "ne" && (layout[upY][rightX] == NULL)) directions[4] = "";
    if(directions[5] == "nw" && (layout[upY][leftX] == NULL)) directions[5] = "";
    if(directions[6] == "se" && (layout[downY][rightX] == NULL)) directions[6] = "";
    if(directions[7] == "sw" && (layout[downY][leftX] == NULL)) directions[7] = "";
    // Checks if is floortile:
    if(directions[0] == "no" && (layout[upY][myX]->getType() != "floortile")) directions[0] = "";
    if(directions[1] == "so" && (layout[downY][myX]->getType() != "floortile")) directions[1] = "";
    if(directions[2] == "ea" && (layout[myY][rightX]->getType() != "floortile")) directions[2] = "";
    if(directions[3] == "we" && (layout[myY][leftX]->getType() != "floortile")) directions[3] = "";
    if(directions[4] == "ne" && (layout[upY][rightX]->getType() != "floortile")) directions[4] = "";
    if(directions[5] == "nw" && (layout[upY][leftX]->getType() != "floortile")) directions[5] = "";
    if(directions[6] == "se" && (layout[downY][rightX]->getType() != "floortile")) directions[6] = "";
    if(directions[7] == "sw" && (layout[downY][leftX]->getType() != "floortile")) directions[7] = "";
    while(directions[n] == "") {
        n = rand() % 8;
    }
    if(n==0) {
        moveEnemy(layout,0,-1);
        moveUp();
//cout << "moving north" <<endl ;
    }
    if(n==1) {
        moveEnemy(layout,0,1);
        moveDown();
//cout << "moving south" << endl;
    }
    if(n==2) {
        moveEnemy(layout,1,0);
        moveRight();
//cout << "moving east" << endl;
    }
    if(n==3) {
        moveEnemy(layout,-1,0);
        moveLeft();
//cout << "moving west" << endl;
    }
    if(n==4) {
        moveEnemy(layout,1,-1);
        moveUp();
        moveRight();
//cout << "moving northeast" << endl;
    }
    if(n==5) {
        moveEnemy(layout,-1,-1);
        moveUp();
        moveLeft();
//cout << "moving northwest" << endl;
    }
    if(n==6) {
        moveEnemy(layout,1,1);
        moveDown();
        moveRight();
//cout << "moving southeast" << endl;
    }
    if(n==7) {
        moveEnemy(layout,-1,1);
        moveDown();
        moveLeft();
//cout << "moving southwest" << endl;
    }
}

string Enemy::getRace() {
    return type;
}

void Enemy::merchantAttacked()
{
    merchantHostile = true;
}

//
int Enemy::getATK() {
    return atk;
}

int Enemy::getDEF() {
    return def;
}

bool Enemy::checkMHostile() {
    return merchantHostile;
}

Enemy::Enemy() {}

Enemy::~Enemy() {}
