#include "player.h"
#include <sstream>

using namespace std;

int Player::getATK() {
    return atk + datk;
}

int Player::getDEF() {
    return def + ddef;
}

string Player::getRace() {
    return type;
}
string Player:: getPosType()
{
    return posType;
}
void Player:: setPosType(string s)
{
    posType = s;
}
string Player::getAction()
{
    return action;
}
void Player:: setAction(string s)
{
    action = s;
}
int Player:: getChamberNum()
{
    return chamberNum;
}
void Player:: setChamberNum(int n)
{
    chamberNum = n;
}
bool Player:: isInChamber()
{
    return inChamber;
}
void Player:: setInChamber(bool b)
{
    inChamber = b;
}
// Overridden moves
void Player::moveUp() {
    if(inChamber)
    {
        y -= 1;
    }
    ly -=1;
    moved = true;
}

void Player::moveDown() {
    if(inChamber)
        y += 1;
    ly += 1;
    moved = true;
}

void Player::moveLeft() {
    if(inChamber)
        x -= 1;
    lx -= 1;
    moved = true;
}

void Player::moveRight() {
    if(inChamber)
        x += 1;
    lx += 1;
    moved = true;
}

void Player::addGold(int n) {
    gold += n;
}

int Player::getGold() {
    return gold;
}

void Player::usePotion(Potion* p) {
    int m = p->getMagnitude();
    if(p->getType() == "RH") {
        p->usedRH();
        /*    if(getRace() == "human") {
              changeHP(min(140-m,m)); //increases to max if heals over, or by regular amount
            }
            if(getRace() == "dwarf") {
              changeHP(min(100-m,m)); //increases to max if heals over, or by regular amount
            }
            if(getRace() == "elf") {
              changeHP(min(140-m,m)); //increases to max if heals over, or by regular amount
            }
            if(getRace() == "orc") {
              changeHP(min(180-m,m)); //increases to max if heals over, or by regular amount
            } */
        changeHP(m);
//    setAction(getAction() + " and it restored health");
    }
    if(p->getType() == "BA") {
        p->usedBA();
        changeATK(m);
//    setAction(getAction() + " and it boosted attack");
    }
    if(p->getType() == "BD") {
        p->usedBD();
        changeDEF(m);
//    setAction(getAction() + " and it boosted defence");
    }
    if(p->getType() == "PH") {
        p->usedPH();
        changeHP(max(1+getHP() - p->getMagnitude(),p->getMagnitude() ));
//    setAction(getAction() + " and it poisoned health");
    }
    if(p->getType() == "WA") {
        p->usedWA();
        changeATK(max(-(getATK()),-(p->getMagnitude()))); // so that ATK cannot go below 0
//    setAction(getAction() + " and it weakened attack");
    }
    if(p->getType() == "WD") {
        p->usedWD();
        changeDEF(max(-(getDEF()),-(p->getMagnitude())));
//    setAction(getAction() + " and it weakened defence");
    }
}

void Player::lookPotion(Cell*** layout, int width, int height) {
    Potion * pot = new Potion(0,0,"RH");
    for(int i = max(0,getX()-1); i <= min(height-1, getX()+1); i++) {
        for(int j = max(0,getY()-1); j <= min(height-1,getY()+1); j++) {
            if(layout[i][j]->getType() == "RH") {
                if(pot->knownRH)
                    setAction(getAction() + " and sees a RH potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }
            if(layout[i][j]->getType() == "BA") {
                if(pot->knownBA)
                    setAction(getAction() + " and sees a BA potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }
            if(layout[i][j]->getType() == "BD") {
                if(pot->knownBD)
                    setAction(getAction() + " and sees a BD potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }
            if(layout[i][j]->getType() == "PH") {
                if(pot->knownPH)
                    setAction(getAction() + " and sees a PH potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }
            if(layout[i][j]->getType() == "WA") {
                if(pot->knownWA)
                    setAction(getAction() + " and sees a WA potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }
            if(layout[i][j]->getType() == "WD") {
                if(pot->knownWD)
                    setAction(getAction() + " and sees a WD potion");
                else
                    setAction(getAction() + " and sees an unknown potion");
            }

        }
    }
    delete pot;
}

int Player::getdATK() {
    return datk;
}

void Player::changeATK(int n) {
    datk += n;
}

void Player::changeDEF(int n) {
    ddef += n;
}

void Player::attackEnemy(Enemy* attacked) {
    if(attacked->getType()=="merchant") {
        attacked->merchantAttacked();
        cout << attacked->checkMHostile() << endl;
    }
    int dmg = ceil( ((double)100/(double)(100+attacked->getDEF()) )*getATK());
    attacked->changeHP(-dmg);
    string dmgs;
    ostringstream temp;
    temp << dmg;
    dmgs = temp.str();
    setAction(getAction() + " and did " + dmgs + " damage");
}

void Player::resetStats() {
    datk = 0;
    ddef = 0;
}

void Player::print() {
    cout << '@';
}

Player & Player:: operator=(const Player &other)
{
    // cell
    x = other.x;
    y = other.y;
    lx = other.lx;
    ly = other.ly;
    type = other.type;

    //character
    hp = other.hp;
    atk = other.hp;
    def = other.def;
    moved = other.moved;

    // this
    gold = other.gold;;
    datk = other.datk;
    ddef = other.ddef;
    action = other.action;
    chamberNum = other.chamberNum;
    posType = other.posType;
    inChamber = other.inChamber;
    return *this;

}

Player::Player() {}
Player::~Player() {}
