#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include <string>
#include <iostream>
#include "enemy.h"

class Merchant : public Enemy
{
public:
    //Methods
    void print();
    void attackPlayer(Player* attacked);
    //Constructor
    Merchant(int a, int b);
    //Destructor
    ~Merchant();
};

#endif
