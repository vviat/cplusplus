/*************************************************************************
	> File Name: leishufangfa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月26日 星期三 09时34分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
    private:
        static int cnt; //存在全局变量区
        int a;
    public:
    
    A(){
        cnt++;
    }
    static int getcnt(){
        return cnt;
    }
    ~A(){
        cnt--;
    }
    static int getA(A &t){
        return t.a;//
    }
};

int A::cnt = 0;
int main(){
    cout<< A::getcnt()<<endl;//可以通过类名去访问
    A t;
    cout << t.getcnt()<<endl;//对象可以访问类方法
    return 0;
}
