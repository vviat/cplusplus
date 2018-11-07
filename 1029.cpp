/*************************************************************************
	> File Name: 1029.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月29日 星期一 18时48分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a[2][3] = {{1,2,3},{4,5,5}};
    int *p;
    p = &a[0][0];
    cout<<*(p + 3)<<endl;
    cout<<(p + 3)<<endl;
    cout<<*(&a[1][0])<<endl;

    return 0;
}
