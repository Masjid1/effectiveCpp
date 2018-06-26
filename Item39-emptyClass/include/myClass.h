#ifndef MYCLASS_H
#define MYCLASS_H


class myClass
{
    public:
        myClass();
        virtual ~myClass();

    protected:

    private:
};

class Empty { };
class HoldsAnChar {
    char c;
};
class HoldsAnCharAndEmpty {
    char c;
    Empty e;
};
class HoldsAnInt {
    int i;
};
class HoldsAnIntAndEmpty {
    int i;
    Empty e;
};
class HoldsAnDouble {
    double d;
};
class HoldsAnDoubleAndEmpty {
    double d;
    Empty e;
};
class HoldsAnCharAndAnDouble {
    char c;
    double d;
};
class HoldsAnCharAndAnDoubleAndEmpty {
    char c;
    double d;
    Empty e;
};
class com{
    HoldsAnCharAndAnDoubleAndEmpty hcde;
};
class comAndEmpty{
    HoldsAnCharAndAnDoubleAndEmpty hcde;
    Empty e;
};
class DerivedbyEmpty : public Empty{ };
class DerivedbyEmptyHasAnInt : public Empty{
    int i;
};
class EmptyClass{
    typedef int I32;
    using U8 = unsigned char;
    enum Color {Red, Green, Blue};
    static int si;
    void nonVirtualFunction();

};
#endif // MYCLASS_H
