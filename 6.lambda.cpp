/*************************************************************************
	> File Name: 6.lambda.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月17日 星期三 10时38分01秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

/*int main(){
    auto add = [](int a, int b)->double {//[]函数名[]内放变量　捕获变量，()参数列表
        return a + b;
    };
    auto f= [](int n) {
        if(n <= 2) return n;
        return f(n - 1) + f(n - 2);
    };
    cout << add(4,5) << endl;
    return 0;
}*/
template <T> 
auto func(T x) -> decltype(x(0,0)){
    return x(4, 5);
}

int  getAdd() {
    int x = 0, y = 1 , z = 2;
    auto test = [x, &y, &z](int a, int b) -> double{//引用捕获&x...
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
        x += 1, y += 1, z += 1;
        return a + b;
    };

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    return 0;
}
int main() {
    int obj_a;
    auto add = [](int a, int b) -> double{
        obj_a += 1;
        return a + b + 2.1;

    };
    auto add2 = [](int a, int b) -> const char *{
        return "hello world";
    };
    std::functional<int(int)> f = [&](int n) ->int {
        if(n <= 2) return  n;
        return f(n - 1) + f(n - 2);
    };
    cout << func(add) << endl;
    cout << func(add2) << endl;
    cout << func
   return 0;
}
