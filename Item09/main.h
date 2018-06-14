#include <iostream>
#include <string>
#include <cstdio>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

class Transaction {
public:
    explicit Transaction(const string& logInfo) {
        cout << "enter Transaction's ctor.\n";
        logTransaction(logInfo);
        cout << "exit Transaction's ctor.\n";
    }
    void logTransaction(const string& logInfo) const {
        cout << "enter Transaction's logTransaction.\n";
        cout << "\tTransaction:\n\t\t" << logInfo << endl << "\t\t" << string(50, '-') << endl;
        cout << "exit Transaction's logTransaction.\n";
    }
};

class BuyTransaction : public Transaction {
public:
    explicit BuyTransaction(int para)
     : Transaction(createLogString(para)) { }
private:
    string createLogString(int para) {
        char buf[10];
///        cout << itoa(para, buf, 10); // 此编译器不支持itoa函数。
        sprintf(buf, "%d;", para);
        return string("buy log: +") + string(buf);
    }
};

class SellTransaction : public Transaction {
public:
    explicit SellTransaction(int para)
     :
     Transaction(createLogString(para)) { }
private:
     static string createLogString(int para) {
        char buf[20];
        sprintf(buf, "%d;", para+a);
        /// b;
        return string("sell log: -") + buf;
    }
    static int a;
///    int b;
/// error: invalid use of member 'SellTransaction::b' in static member function|
/// static member function 中只能使用static member variant.
};

int SellTransaction::a = 100;
