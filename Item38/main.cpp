// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include <iostream>
#include <string>
#include "Set.h"
#include <set>

using std::cout;
using std::endl;
using std::string;

int main()
{
    Set<int> s;
//    std::set<int> s;
    for(int i=0; i<5; ++i){
        s.insert(3*i+1);
    }
    s.insert(1);
    s.insert(4);
    s.insert(14);
    s.remove(4);
//    s.erase(4);

    for(auto ite=s.begin(); ite!=s.end(); ++ite){
        cout << *ite << " ";
    }

//    for(typename std::set<int>::iterator ite=s.begin(); ite != s.end(); ++ite){
//        cout << *ite << " ";
//    }
    cout << endl;
    return 0;
}
