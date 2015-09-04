#ifndef __STAIRS_H__
#define __STAIRS_H__
#include <string>
#include <iostream>
#include "cell.h"

class Stairs : public Cell
{
public:
    //Methods
    void print();
    //Constructors
    Stairs(int nx, int ny);
    //Destructor
    ~Stairs();
};

#endif
