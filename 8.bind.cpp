/*************************************************************************
	> File Name: 8.bind.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月17日 星期三 11时59分46秒
 ************************************************************************/

#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using std::bind;
using std::placeholders::_1;
using std::placeholders::_2;

int add(int a, int b) {
    return a+ b;
}

int main(){
    auto add4 = bind(add, _1, 4);
    cout << add4(5) << endl;
    add4(6);
    return 0;
}
