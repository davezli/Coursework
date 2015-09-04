#include "dwarf.h"

int Dwarf::getGold() {
    return (2*gold);
}

Dwarf::Dwarf(int a, int b) {
    x = a;
    y = b;
    type = "dwarf";
    action = "Player character has spawned";
    hp = 100;
    atk = 20;
    datk = 0;
    def = 30;
    ddef = 0;
    moved = false;
    gold = 0;
}

Dwarf::~Dwarf() {}
