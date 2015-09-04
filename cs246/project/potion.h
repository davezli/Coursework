#ifndef __POTION_H__
#define __POTION_H__
#include <string>
#include <iostream>
#include "item.h"

class Potion : public Item
{
protected:
    int magnitude;
public:
    static bool knownRH;
    static bool knownBA;
    static bool knownBD;
    static bool knownPH;
    static bool knownWA;
    static bool knownWD;
public:
    //Methods
    int getMagnitude();
    static void usedRH();
    static void usedBA();
    static void usedBD();
    static void usedPH();
    static void usedWA();
    static void usedWD();
    //Constructors
    Potion(int a, int b, std::string s);
    //Destructor
    ~Potion();
};

#endif
