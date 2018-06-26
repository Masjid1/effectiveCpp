#include "Shape2.h"
#include <iostream>

Shape2::Shape2()
{
    //ctor
}

Shape2::~Shape2()
{
    //dtor
}

void Shape2::draw(ShapeColor color) const
{
    std::cout << "Shape2::draw " << color << std::endl;
    drawImpl();
}

void Shape2::drawImpl() const
{
    std::cout << "Shape2::drawImpl\n";
}

void Rectangle2::drawImpl() const
{
    std::cout << "Rectangle2::drawImpl\n";
}
