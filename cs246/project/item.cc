#include "item.h"

bool Item::isPotion() {
    return(getType()=="RH"||getType()=="BA"||getType()=="BD"||getType()=="PH"||getType()=="WA"||getType()=="WD");
}

Item::Item() {}
Item::~Item() {}

