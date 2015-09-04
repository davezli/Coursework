#include <cmath>
#include "elf.h"

void Elf::usePotion(Potion* p) {
    if(p->getType() == "RH"||p->getType() == "PH")
        changeHP((int)abs(p->getMagnitude()));
    if(p->getType() == "BA"||p->getType() == "WA")
        changeATK((int)abs(p->getMagnitude()));
    if(p->getType() == "BD"||p->getType() == "WD")
        changeDEF((int)abs(p->getMagnitude()));
    // add deleting potion & adding floor tile
}

Elf::Elf(int a, int b) {
    x = a;
    y = b;
    type = "elf";
    action = "Player character has spawned";
    hp = 140;
    atk = 30;
    datk = 0;
    def = 10;
    ddef = 0;
    moved = false;
    gold = 0;
}

Elf::~Elf() {}
