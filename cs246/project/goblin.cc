#include "goblin.h"

using namespace std;

void Goblin::print() {
    cout << 'N';
}

Goblin::Goblin(int a, int b) {
    x = a;
    y = b;
    type = "goblin";
    hp = 70;
    atk = 5;
    def = 10;
    moved = false;
}

Goblin::~Goblin() {}
