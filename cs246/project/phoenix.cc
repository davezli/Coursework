#include "phoenix.h"

using namespace std;

void Phoenix::print() {
    cout << 'X';
}

Phoenix::Phoenix(int a, int b) {
    x = a;
    y = b;
    type = "phoenix";
    hp = 50;
    atk = 35;
    def = 20;
    moved = false;
}

Phoenix::~Phoenix() {}
