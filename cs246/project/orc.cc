#include "orc.h"

int Orc::getGold() {
    return gold*0.5;
}

Orc::Orc(int a, int b) {
    x = a;
    y = b;
    type = "orc";
    action = "Player character has spawned";
    hp = 180;
    atk = 30;
    datk = 0;
    def = 25;
    ddef = 0;
    moved = false;
    gold = 0;
}

Orc::~Orc() {}
