#include "character.h"

using namespace std;

int Character::getHP() {
    return hp;
}

int Character::getATK() {
    return atk;
}

int Character::getDEF() {
    return def;
}

void Character::changeHP(int n) {
    hp = hp + n;
}

void Character::moveUp() {
    y -= 1;
    ly -=1;
    moved = true;
}

void Character::moveDown() {
    y += 1;
    ly += 1;
    moved = true;
}

void Character::moveLeft() {
    x -= 1;
    lx -= 1;
    moved = true;
}

void Character::moveRight() {
    x += 1;
    lx += 1;
    moved = true;
}

bool Character::hasMoved() {
    return(moved);
}

bool Character::isEnemy() {
    return (type=="werewolf"||type=="goblin"||type=="troll"||type=="phoenix"||type=="merchant"||type=="vampire"||type=="dragon");
}

void Character::resetMoved() {
    moved = false;
}
