#include "myClass.h"
#include <iostream>

myClass::myClass()
{
    //ctor
}

myClass::~myClass()
{
    //dtor
}

void EmptyClass::nonVirtualFunction(){ std::cout << "this is a non-virtual function.\n"; }
