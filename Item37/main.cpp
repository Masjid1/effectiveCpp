#include <iostream>
#include "Shape.h"
#include "Shape2.h"

using namespace std;

int main()
{
    Rectangle r;
    Rectangle* pr = &r;
    Shape *ps = &r;

    r.draw();   // Rectangle 1
    /// 派生类指针不存在多态问题, 函数和默认参数均为派生类的.
    pr->draw(); // Rectangle 1
    /// 基类指针与虚函数结合会动态绑定调用派生类的函数, 默认参数静态绑定基类函数的默认参数 Red(0).
    ps->draw(); // Rectangle 0

    Circle c; // error: 缺少参数
    Circle* pc = &c;
    Shape *ps2 = &c;

    // draw函数被重写且为提供默认参数,所以必须指定参数.
    c.draw(Shape::ShapeColor::Blue);    // Circle 2
    /// 派生类指针不存在多态问题, 函数和参数均为派生类的, 所以必须指定参数.
    pc->draw(Shape::ShapeColor::Blue);  // Circle 2
    /// 基类指针与虚函数结合会动态绑定调用派生类的函数, 默认参数静态绑定基类函数的默认参数 Red(0).
    ps2->draw();                        // Circle 0

    cout << "-------------------------------------------------------------------------\n";
    cout << "为避免使用基类指针时,虚函数参数的静态绑定带来的混淆.应该考虑虚函数的替代方案.\n";
    cout << "-------------------------------------------------------------------------\n";
    Rectangle2 r2;
    Rectangle2* pr2 = &r2;
    Shape2 *ps_2 = &r2;

    /// non-virtual member function's default parameter
    /// 三者均使用基类的函数和基类函数的默认参数Shape2::draw 0.
    /// 使用真实对象的成员函数Rectangle2::drawImpl.
    r2.draw();      // Shape2::draw 0 Rectangle2::drawImpl
    pr2->draw();    // Shape2::draw 0 Rectangle2::drawImpl
    ps_2->draw();   // Shape2::draw 0 Rectangle2::drawImpl

    cout << "Hello world!" << endl;
    return 0;
}
