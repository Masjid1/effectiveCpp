#include <iostream>
#include <vector>

/**
C++可以对类模板进行全特化、偏特化；对函数模板可以进行全特化，但不能偏特化（部分编译器错误的接受它）。

全特化(无模板参数T, T=Widget。特点: template<>,名字后有 类型 <Widget>, 函数模板名字后的类型可以省略):
    template<>
    void swap<Widget>(Widget& a, Widget& b) { ... }

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
    template<typename T>
    class WidgetImpl {
    public:
        WidgetImpl(int n=0) : num(n) {
            if(num>0){
                setNum(num);
            }
        }
        void setNum(int n)
        {
            num=n;
            v.clear();
            for(int i=0; i< num; ++i){
                v.push_back(num);
            }
        }
        int getNum()
        {
            return num;
        }
    // 成员变量应该是private的。
    private:
        int num;
        std::vector<T> v;
    };

    template<typename T>
    class Widget {
    public:
        Widget(int n) : pImpl(new WidgetImpl<T>(n)) { }
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
        void swap(Widget<T>& rhs)
        {
            std::cout << "win::Widget::swap begin\n";
            using std::swap;
            swap(pImpl, rhs.pImpl); // 使用全局作用域或pImpl类型所属命名空间中的swap, 或者std::swap。
            std::cout << "win::Widget::swap end\n";
        }
    private:
        WidgetImpl<T>* pImpl;
    };

    // 最终具体的交换有此函数完成, 此函数为偏特化实现T -> WidgetImpl<T>*。
    template<typename T>
    void swap(WidgetImpl<T>* lhs, WidgetImpl<T>* rhs)
    {
        std::cout << "swap WidgetImpl begin\n";
        int num_of_lhs = lhs->getNum(); // backup lhs
        lhs->setNum(rhs->getNum()); // copy rhs to lhs
        rhs->setNum(num_of_lhs); // copy lhs's duplicate to rhs.
        std::cout << "swap WidgetImpl end\n";

    }
    /// 1. 类所在命名空间内Widget专属的non-member swap.
    template<typename T>
    void swap(Widget<T>& lhs, Widget<T>& rhs)
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
    void swap(win::Widget<int>& lhs, win::Widget<int>& rhs)
    {
        cout << "2. std::swap begin\n";
        lhs.swap(rhs);
        cout << "2. std::swap end\n";
    }

    /// 函数模板偏特化是不允许的。
    /// error: non-type partial specialization 'swap<win::Widget<T> >' is not allowed
    /**
    template<typename T>
    void swap<win::Widget<T>>(win::Widget<T>& lhs, win::Widget<T>& rhs)
    {
        cout << "22. std::swap begin\n";
        lhs.swap(rhs);
        cout << "22. std::swap end\n";
    }
    */

    /// 函数重载
    /// 《Effective C++》P109 中说std中不能添加新的template，
    /// 添加后虽然可以编译和执行，但他们的行为是没有明确定义。
    /// 本程序中会引起swap名字查找冲突，提示有二义性。
    /// error: call of overloaded 'swap(win::Widget<int>&, win::Widget<int>&)' is ambiguous
    /**
    template<typename T>
    void swap(win::Widget<T>& lhs, win::Widget<T>& rhs)
    {
        cout << "22. std::swap begin\n";
        lhs.swap(rhs);
        cout << "22. std::swap end\n";
    }
    */

}
