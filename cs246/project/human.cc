#include "human.h"

Human::Human(int a, int b) {
    x = a;
    y = b;
    type = "human";

// action = "Player character has spawned";
    hp = 140;
    atk = 20;
    datk = 0;
    def = 20;
    ddef = 0;
    moved = false;
    gold = 0;
}

Human::~Human() {}
