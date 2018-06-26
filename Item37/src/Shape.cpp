#include "Shape.h"
#include <iostream>

Shape::Shape()
{
    //ctor
}

Shape::~Shape()
{
    //dtor
}

/// 成员函数默认参数必须在声明时指定, 且成员函数实现时不能再次指定, 即使两次的值相同也不可以.
void Rectangle::draw(ShapeColor color) const
{
    std::cout << "draw a rectangle with color " << color << std::endl;
}

void Circle::draw(ShapeColor color) const
{
    std::cout << "draw a circle with color " << color << std::endl;
}
