#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <string>
#include <iostream>
#include "cell.h"

class Passage : public Cell
{
public:
    //Methods
    void print();
    bool isDoor();
    void setDoor();
    //Constructors
    Passage();
    Passage(int x, int y);
    //Destructor
    ~Passage();
};

#endif
