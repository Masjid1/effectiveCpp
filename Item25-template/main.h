#include <iostream>
#include <vector>

/**
C++���Զ���ģ�����ȫ�ػ���ƫ�ػ����Ժ���ģ����Խ���ȫ�ػ���������ƫ�ػ������ֱ���������Ľ���������

ȫ�ػ�(��ģ�����T, T=Widget���ص�: template<>,���ֺ��� ���� <Widget>, ����ģ�����ֺ�����Ϳ���ʡ��):
    template<>
    void swap<Widget>(Widget& a, Widget& b) { ... }

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
    // ��Ա����Ӧ����private�ġ�
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
            *pImpl = *(rhs.pImpl); // ��Ȼ"."�����ȼ�����"*"������Ϊ���׶���ʹ��������һ�ֺõı�ʾ��
            return *this;
        }
        // swap��Ա���������Widget����������Ż��汾��
        void swap(Widget<T>& rhs)
        {
            std::cout << "win::Widget::swap begin\n";
            using std::swap;
            swap(pImpl, rhs.pImpl); // ʹ��ȫ���������pImpl�������������ռ��е�swap, ����std::swap��
            std::cout << "win::Widget::swap end\n";
        }
    private:
        WidgetImpl<T>* pImpl;
    };

    // ���վ���Ľ����д˺������, �˺���Ϊƫ�ػ�ʵ��T -> WidgetImpl<T>*��
    template<typename T>
    void swap(WidgetImpl<T>* lhs, WidgetImpl<T>* rhs)
    {
        std::cout << "swap WidgetImpl begin\n";
        int num_of_lhs = lhs->getNum(); // backup lhs
        lhs->setNum(rhs->getNum()); // copy rhs to lhs
        rhs->setNum(num_of_lhs); // copy lhs's duplicate to rhs.
        std::cout << "swap WidgetImpl end\n";

    }
    /// 1. �����������ռ���Widgetר����non-member swap.
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
    /// 2. std�����ռ���Widgetר�����ػ��汾
    /// ����ȫ�ػ�std�����е�template��������������µ�template(�µĺ�������)��std�С�
    /// ģ���ȫ�ػ�����Ҫ��template<>��������Ϊ��ģ�庯����
    template<>
    void swap(win::Widget<int>& lhs, win::Widget<int>& rhs)
    {
        cout << "2. std::swap begin\n";
        lhs.swap(rhs);
        cout << "2. std::swap end\n";
    }

    /// ����ģ��ƫ�ػ��ǲ�����ġ�
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

    /// ��������
    /// ��Effective C++��P109 ��˵std�в�������µ�template��
    /// ��Ӻ���Ȼ���Ա����ִ�У������ǵ���Ϊ��û����ȷ���塣
    /// �������л�����swap���ֲ��ҳ�ͻ����ʾ�ж����ԡ�
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
