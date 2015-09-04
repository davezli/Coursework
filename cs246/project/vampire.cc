#include "vampire.h"

using namespace std;

void Vampire::print() {
    cout << 'V';
}

Vampire::Vampire(int a, int b) {
    x = a;
    y = b;
    type = "vampire";
    hp = 50;
    atk = 25;
    def = 25;
    moved = false;
}

Vampire::~Vampire() {}
