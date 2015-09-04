#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <sstream>

class Floor
{
public:
    // Size of the floor
    int width;
    int height;
    char **display; // Represent with a 2-D array of char
    virtual void print() = 0;
    virtual void tick() = 0;
    virtual void spawn() = 0;
};

#endif
