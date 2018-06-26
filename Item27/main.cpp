#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Window
{
public:
    /// �������麯��"virtual retType func() = 0"����Ϊabstract type, can't used to declare variable.
    virtual void blink() = 0;//{ cout << "it is just for its derived classes.\n"; }

    /// ֻ���������壬��WindowΪ���������ͣ���̳���ʵ���˸��麯�����������������͡�Ч���봿�麯����ͬ���������麯���﷨�ϸ�������
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
        /// ��̬ת�ͣ��ɹ��򷵻ص�ַ��ʧ���򷵻�nullptr��0����Ϊ������Ϊ�ж�������
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
