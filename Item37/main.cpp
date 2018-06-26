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
    /// ������ָ�벻���ڶ�̬����, ������Ĭ�ϲ�����Ϊ�������.
    pr->draw(); // Rectangle 1
    /// ����ָ�����麯����ϻᶯ̬�󶨵���������ĺ���, Ĭ�ϲ�����̬�󶨻��ຯ����Ĭ�ϲ��� Red(0).
    ps->draw(); // Rectangle 0

    Circle c; // error: ȱ�ٲ���
    Circle* pc = &c;
    Shape *ps2 = &c;

    // draw��������д��Ϊ�ṩĬ�ϲ���,���Ա���ָ������.
    c.draw(Shape::ShapeColor::Blue);    // Circle 2
    /// ������ָ�벻���ڶ�̬����, �����Ͳ�����Ϊ�������, ���Ա���ָ������.
    pc->draw(Shape::ShapeColor::Blue);  // Circle 2
    /// ����ָ�����麯����ϻᶯ̬�󶨵���������ĺ���, Ĭ�ϲ�����̬�󶨻��ຯ����Ĭ�ϲ��� Red(0).
    ps2->draw();                        // Circle 0

    cout << "-------------------------------------------------------------------------\n";
    cout << "Ϊ����ʹ�û���ָ��ʱ,�麯�������ľ�̬�󶨴����Ļ���.Ӧ�ÿ����麯�����������.\n";
    cout << "-------------------------------------------------------------------------\n";
    Rectangle2 r2;
    Rectangle2* pr2 = &r2;
    Shape2 *ps_2 = &r2;

    /// non-virtual member function's default parameter
    /// ���߾�ʹ�û���ĺ����ͻ��ຯ����Ĭ�ϲ���Shape2::draw 0.
    /// ʹ����ʵ����ĳ�Ա����Rectangle2::drawImpl.
    r2.draw();      // Shape2::draw 0 Rectangle2::drawImpl
    pr2->draw();    // Shape2::draw 0 Rectangle2::drawImpl
    ps_2->draw();   // Shape2::draw 0 Rectangle2::drawImpl

    cout << "Hello world!" << endl;
    return 0;
}
