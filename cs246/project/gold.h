#ifndef __GOLD_H__
#define __GOLD_H__
#include <string>
#include <iostream>
#include "item.h"

class Gold : public Item
{
protected:
    int amount;
public:
    //Methods
    int getAmount();
    //Constructors
    Gold(int a, int b, int val);
    //Destructor
    ~Gold();
};

#endif
