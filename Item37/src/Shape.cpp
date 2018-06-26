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

/// ��Ա����Ĭ�ϲ�������������ʱָ��, �ҳ�Ա����ʵ��ʱ�����ٴ�ָ��, ��ʹ���ε�ֵ��ͬҲ������.
void Rectangle::draw(ShapeColor color) const
{
    std::cout << "draw a rectangle with color " << color << std::endl;
}

void Circle::draw(ShapeColor color) const
{
    std::cout << "draw a circle with color " << color << std::endl;
}
