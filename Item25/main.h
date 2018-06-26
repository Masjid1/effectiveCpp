#include <iostream>
#include <vector>

/**
C++可以对类模板进行全特化、偏特化；对函数模板可以进行全特化，但不能偏特化（部分编译器支持）。

全特化(无模板参数T, T=Widget。特点: template<>,名字后有 类型 <Widget>, 函数模板名字后的类型可以省略):
    template<>
    void swap<Widget>(Widget& a, Widget& b) { ... }

    template<>
    void swap(Widget& a, Widget& b) { ... }

偏特化(有模板参数T, 特化为Widget<T>, swap必须是一个类模板。特点: 名字后有 模板类型T的组合 <Widget<T>>):
    template<typename T>
    class swap<Widget<T>> { ... }

函数重载(函数参数由T改为Widget<T>,函数名不变，参数个数或类型不同是函数重载特点: 名字后无类型):
    template<typename T>
    void swap(Widget<T>& a, Widget<T>& b) { ... }
*/

namespace win {

     // WidgetImpl封装内容，Widget封装操作。
    class WidgetImpl {
    public:
    // 成员变量应该是private的。
    private:
        int a,b,c;
        std::vector<double> v;
    };


    class Widget {
    public:
        Widget() { std::cout << "Widget::Widget()\n"; }
        Widget(const Widget& rhs) // coping constructor fucntion
        {
            *pImpl = *(rhs.pImpl);
        }
        Widget& operator=(const Widget& rhs) // assign coping operator
        {
            *pImpl = *(rhs.pImpl); // 虽然"."的优先级高于"*"，但是为了易读，使用括号是一种好的表示。
            return *this;
        }
        // swap成员函数，针对Widget对象的内置优化版本。
        void swap(Widget& rhs)
        {
            std::cout << "win::Widget::swap begin\n";
            using std::swap;
            swap(pImpl, rhs.pImpl);
            std::cout << "win::Widget::swap end\n";
        }
    private:
        WidgetImpl* pImpl;
    };

    /// 1. 类所在命名空间内Widget专属的non-member swap.
    void swap(Widget& lhs, Widget& rhs)
    {
        std::cout << "1. win::swap begin\n";
        lhs.swap(rhs);
        std::cout << "1. win::swap end\n";
    }

}

namespace std {
    /**
    template<typename T>
    void swap(T& a, T& b)
    {
        T temp(a);
        a = b;
        b = temp;
    }
    */
    /// 2. std命名空间内Widget专属的特化版本
    /// 可以全特化std内现有的template，但不可以添加新的template(新的函数或类)到std中。
    /// 模板的全特化必须要有template<>，否则视为非模板函数。
    template<>
    void swap(win::Widget& lhs, win::Widget& rhs)
    {
        cout << "2. std::swap begin\n";
        lhs.swap(rhs);
        cout << "2. std::swap end\n";
    }
}
