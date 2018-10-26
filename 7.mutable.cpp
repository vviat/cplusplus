/*************************************************************************
	> File Name: 7.mutable.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月17日 星期三 11时25分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public :
    int getX() const {//const 方法不能修改方法内任何值　const方法不能调用非ｃｏｎｓｔ方法，要想改就需要加mutable关键字
    this->getCnt += 1;
    return this->x;
    }
    void add(){
        this->x += 1;
        return ;
    }
private:
    int x;
    mutable int getCnt = 0;//加了这个关键字就可以改；
}
