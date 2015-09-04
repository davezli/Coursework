#include "werewolf.h"

using namespace std;

void Werewolf::print() {
    cout << 'W';
}

Werewolf::Werewolf(int a, int b) {
    x = a;
    y = b;
    type = "werewolf";
    hp = 120;
    atk = 30;
    def = 5;
    moved = false;
}

Werewolf::~Werewolf() {}
