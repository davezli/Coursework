#include "merchant.h"
#include <sstream>

using namespace std;

void Merchant::print() {
    cout << 'M';
}

void Merchant::attackPlayer(Player* attacked) {
    if(checkMHostile() == true) {
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
}

Merchant::Merchant(int a, int b) {
    x = a;
    y = b;
    type = "merchant";
    hp = 30;
    atk = 70;
    def = 5;
    moved = false;
}

Merchant::~Merchant() {}
