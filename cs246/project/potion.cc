#include "potion.h"

using namespace std;

bool Potion::knownRH = false;
bool Potion::knownBA = false;
bool Potion::knownBD = false;
bool Potion::knownWA = false;
bool Potion::knownPH = false;
bool Potion::knownWD = false;

int Potion::getMagnitude() {
    return magnitude;
}
//*
void Potion::usedRH() {
    knownRH = true;
}

void Potion::usedBA() {
    knownBA = true;
}

void Potion::usedBD() {
    knownBD = true;
}

void Potion::usedPH() {
    knownPH = true;
}

void Potion::usedWA() {
    knownWA = true;
}

void Potion::usedWD() {
    knownWD = true;
}

Potion::Potion(int a, int b, string s) {
    x = a;
    y = b;
    type = s;
    if(s == "RH" || s == "PH")
        magnitude = 10;
    else
        magnitude = 5;
}

Potion:: ~Potion() {}
