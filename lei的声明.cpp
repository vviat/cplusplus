/*************************************************************************
	> File Name: lei的声明.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月17日 星期一 10时15分20秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
class people {
    private :
        int a;
        string m_name;
        int *data;
    public :
    people(){ 
        a= 0;  
        //构造函数与普通函数区别：构造函数无返回值类型，自动调用，创建对象用；
        //函数名必须是类名
        cout << "p的无参的构造函数"<<endl;
    }
    people(string name, int a) {
        this->m_name = name;
        data = new int(a);
        cout<<"p的有参的构造函数"<<endl;
    }

    people(const people & obj){ //重写拷贝构造函数（浅拷贝->深拷贝）
        a = obj.a;
        m_name = obj.m_name;
        data = new int;
        * data = *obj.data;
        cout<<"111233"<<endl;
    }
    void setValue (int v);
    int getValue();
    string getname();
    int* getAdd();
};

void people::setValue(int v) {
    this->a = v;
    return ;
}


int people::getValue(){
    return this->a;
}

string people::getname(){
    return this->m_name;
}

int* people::getAdd(){
    return data;
}
int main(){
    people p;
    people* p1 = new people;//在堆上建一个类类型的变量，变量名为p1
    people* p2 = new people("ygy", 6);
    people* p3 = new people("111", 7);
    cout<<p2->getname()<<endl;
    cout<<p3->getname()<<endl;
    people p4("ygy", 1);
    people p5(p4);
    cout<<p4.getAdd()<<endl;
    cout<<p5.getAdd()<<endl;
    p1->setValue(7);
    int* ming = new int;//在堆上开一个int×的变量,变量名为ming
    int* m = new int(1);//申请并初始化
    int* a = new int[10];//用new的时候自动调用构造函数
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    delete m;
    delete[] a;
    //p.setValue(6);
    //cout << p.getValue() << endl;
    return 0;
}
