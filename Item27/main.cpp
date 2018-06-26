#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Window
{
public:
    /// 包含纯虚函数"virtual retType func() = 0"的类为abstract type, can't used to declare variable.
    virtual void blink() = 0;//{ cout << "it is just for its derived classes.\n"; }

    /// 只声明不定义，则Window为不完整类型，其继承类实现了该虚函数，所以是完整类型。效果与纯虚函数相同，不过纯虚函数语法上更完整。
    /// virtual void blink();
};
class SpecialWindow1 : public Window
{
public:
    void blink()
    {
        cout << "SpecialWindow1 blink\n";
    }

};
class SpecialWindow2 : public Window
{
public:
    void blink()
    {
        cout << "SpecialWindow2 blink\n";
    }

};
class SpecialWindow3 : public Window
{
public:
    void blink()
    {
        cout << "SpecialWindow3 blink\n";
    }

};
typedef vector<shared_ptr<Window>> VPW;

int main()
{
    SpecialWindow1 sw1;
    SpecialWindow2 sw2;
    SpecialWindow3 sw3;
    VPW winPtrs;
    winPtrs.push_back(shared_ptr<Window>(&sw1));
    winPtrs.push_back(shared_ptr<Window>(&sw2));
    winPtrs.push_back(shared_ptr<Window>(&sw3));

    for(VPW::iterator iter = winPtrs.begin();
        iter != winPtrs.end(); ++iter)
    {
        /// 1. dynamic_cast
//        cout << "dynamic_cast<SpecialWindow1*>(iter->get()):\n" << (nullptr==dynamic_cast<SpecialWindow1*>(iter->get())) << endl;
        /// 动态转型，成功则返回地址，失败则返回nullptr即0。因为可以作为判断条件。
        /// std::shared_ptr.get(): Get pointer
//        if(SpecialWindow1* psw1 = dynamic_cast<SpecialWindow1*>(iter->get())){
//            psw1->blink();
//        }else if(SpecialWindow2* psw2 = dynamic_cast<SpecialWindow2*>(iter->get())){
//            psw2->blink();
//        }else if(SpecialWindow3* psw3 = dynamic_cast<SpecialWindow3*>(iter->get())){
//            psw3->blink();
//        }

        /// use virtual member function
        iter->get()->blink();
    }

//    Window w;
//    w.blink();
    cout << "Hello world!" << endl;
    return 0;
}
