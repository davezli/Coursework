#include "stairs.h"

using namespace std;

void Stairs::print() {
    cout << '\\';
}

Stairs:: Stairs(int nx, int ny)
{
    x = nx;
    y = ny;
    type = "stairs";
}

Stairs:: ~Stairs() {}
