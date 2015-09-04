#include "gold.h"
using namespace std;

int Gold::getAmount() {
    return amount;
}

Gold::Gold(int a, int b, int val) {
    x = a;
    y = b;
    amount = val;
    type = "gold";
}

Gold::~Gold() {}

