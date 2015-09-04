#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>
#include <iostream>
#include "cell.h"

class Item : public Cell {
public:
    //Methods
    bool isPotion();
    //Constructors
    Item();
    //Destructor
    ~Item();
};

#endif
