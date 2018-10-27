/*************************************************************************
	> File Name: 9.example.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月17日 星期三 14时29分21秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;
auto Pair = [](auto u, auto v) {
    return [=](auto f) {
        return f(u,v);
    };
};
auto First = [](auto t){
    return t([](auto u, auto v) {
        return u;
    });
};
auto Second = [](auto t){
    return t([](auto u,auto v){
        return v;
    });
};

void PrintAll(nullptr_t){

}

template<typename T>
void PrintAll(T t){
    cout << First(t) <<endl;
    PrintAll(Second(t));
}

int main(){
    auto t = Pair(1,"two");
    auto one = First(t);
    auto two = Second(t);
    cout << one << "," << two <<endl;
    auto numbers = Pair(1,Pair(2,Pair(3,Pair(4,Pair(5,nullptr)))));
    PrintAll(numbers);
    return 0;
}
