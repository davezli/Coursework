#include "dragongold.h"
using namespace std;

int DragonGold::getAmount()
{
    return amount;
}
bool DragonGold::isDragonDead()
{
    return dragonDead;
}

void DragonGold::killDragon()
{
    dragonDead = true;
}
Dragon * DragonGold:: getDragon()
{
    return d;
}
void DragonGold:: setDragon(Dragon * dr)
{
    d = dr;
}
DragonGold::DragonGold(int a, int b) {
    x = a;
    y = b;
    amount = 4;
    type = "dragongold";
}

DragonGold::~DragonGold() {}

