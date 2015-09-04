#include "troll.h"

using namespace std;

void Troll::print() {
    cout << 'T';
}

Troll::Troll(int a, int b) {
    x = a;
    y = b;
    type = "troll";
    hp = 120;
    atk = 30;
    def = 5;
    moved = false;
}

Troll::~Troll() {}
