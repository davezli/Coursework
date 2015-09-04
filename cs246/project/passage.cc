#include "passage.h"

using namespace std;

bool Passage::isDoor() {
    return(getType()=="door");
}

void Passage::setDoor() {
    type = "door";
}

void Passage::print() {
    if(isDoor())
        cout << '+';
    else
        cout << '#';
};

Passage:: Passage()
{
    type = "passage";
    x = 0;
    y = 0;
}

Passage:: Passage(int nx, int ny)
{
    type = "passage";
    x = nx;
    y = ny;
}

Passage:: ~Passage() {};
