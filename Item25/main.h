#include <iostream>
#include <vector>

/**
C++���Զ���ģ�����ȫ�ػ���ƫ�ػ����Ժ���ģ����Խ���ȫ�ػ���������ƫ�ػ������ֱ�����֧�֣���

ȫ�ػ�(��ģ�����T, T=Widget���ص�: template<>,���ֺ��� ���� <Widget>, ����ģ�����ֺ�����Ϳ���ʡ��):
    template<>
    void swap<Widget>(Widget& a, Widget& b) { ... }

    template<>
    void swap(Widget& a, Widget& b) { ... }

ƫ�ػ�(��ģ�����T, �ػ�ΪWidget<T>, swap������һ����ģ�塣�ص�: ���ֺ��� ģ������T����� <Widget<T>>):
    template<typename T>
    class swap<Widget<T>> { ... }

��������(����������T��ΪWidget<T>,���������䣬�������������Ͳ�ͬ�Ǻ��������ص�: ���ֺ�������):
    template<typename T>
    void swap(Widget<T>& a, Widget<T>& b) { ... }
*/

namespace win {

     // WidgetImpl��װ���ݣ�Widget��װ������
    class WidgetImpl {
    public:
    // ��Ա����Ӧ����private�ġ�
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
            *pImpl = *(rhs.pImpl); // ��Ȼ"."�����ȼ�����"*"������Ϊ���׶���ʹ��������һ�ֺõı�ʾ��
            return *this;
        }
        // swap��Ա���������Widget����������Ż��汾��
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

    /// 1. �����������ռ���Widgetר����non-member swap.
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
    /// 2. std�����ռ���Widgetר�����ػ��汾
    /// ����ȫ�ػ�std�����е�template��������������µ�template(�µĺ�������)��std�С�
    /// ģ���ȫ�ػ�����Ҫ��template<>��������Ϊ��ģ�庯����
    template<>
    void swap(win::Widget& lhs, win::Widget& rhs)
    {
        cout << "2. std::swap begin\n";
        lhs.swap(rhs);
        cout << "2. std::swap end\n";
    }
}
