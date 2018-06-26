
#ifndef SET_H
#define SET_H

#include <list>
#include <iostream>
#include <algorithm>

/**
    container adapter, Set is implemented in terms of std::list.
    注意: GCC g++不支持模板类的分离编译，只能声明和实现写在一起编译。

    未完待续: 修改Set接口使其遵循**STL容器的协议**,从而满足条款18:使接口容易被正确使用,不易被误用.
*/

/**
    Set's declaration.
*/
template<typename T>
class Set
{
public:
    Set();
    /// error: need 'typename' before 'std::__cxx11::list<T>::iterator' because 'std::__cxx11::list<T>' is a dependent scope|
    typename std::list<T>::iterator begin(){ return rep.begin(); }
    typename std::list<T>::iterator end(){ return rep.end(); }
    bool member(const T& item) const;
    void insert(const T& item);
    void remove(const T& item);
    std::size_t size() const;

private:
    std::list<T> rep;
};

/**
    Set's implement.
*/
template<typename T>
Set<T>::Set()
{
    rep.clear();
}

template<typename T>
bool Set<T>::member(const T& item) const
{
    return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template<typename T>
void Set<T>::insert(const T& item)
{
//    typename std::list<T>::iterator pos = std::find(rep.begin(), rep.end(), item);
//    if(pos == rep.end()){ // rep中没有item,则插入.
//        rep.insert(pos, item);
//    }
    if(!member(item)){
        rep.push_back(item);
    }
}

template<typename T>
void Set<T>::remove(const T& item)
{
    typename std::list<T>::iterator pos = std::find(rep.begin(), rep.end(), item);
    if(pos != rep.end()){ // rep中有item,则删除.
        rep.erase(pos);
    }
}

template<typename T>
size_t Set<T>::size() const
{
    return rep.size();
}

#endif // SET_H
