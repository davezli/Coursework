#include "dragon.h"

using namespace std;

void Dragon::print() {
    cout << 'D';
}

DragonGold * Dragon:: getDragonGold()
{
    return dg;
}

Dragon::Dragon(int a, int b) {
    x = a;
    y = b;
    type = "dragon";
    dg = NULL;
    hp = 150;
    atk = 20;
    def = 20;
    moved = false;
}

Dragon::Dragon(int a, int b, DragonGold * drg) {
    x = a;
    y = b;
    type = "dragon";
    dg = drg;
    hp = 150;
    atk = 20;
    def = 20;
    moved = false;
}

Dragon::~Dragon() {}
