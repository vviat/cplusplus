/*************************************************************************
	> File Name: 10.left_right.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月17日 星期三 15时25分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Data {
    public :
    Data() {
        cout << "data" <<endl;
        this->x = 6;
        this->data = new int{0};
    }
    Data(const Data &obj) {
        this->x = 7;
        this->data = new int{0};
        *(this->data) = *(obj.data);
        cout<<"copy"<<endl;
    }
    friend ostream &operator<<(ostream &,const Data &);
private:
    int x;
    int *data;
};

ostream &operator<<(ostream &output, const Data &obj) {
    cout << "(" << obj.x<<","<<obj.data <<")" <<endl;
    return out;
}

template<typename T>
class Array{
public:
    Array() : Array(10){}
    Array(int n){
        this->n = n;
        this->data = new T[this->n];
    }
    Array(const Array &arr) {//深拷贝不容易出问题
        this->n = arr.n;
    }
    T &operator[](int ind){
        if(ind < 0 || ind >= this->n) return this->NIL;
        return this->data[ind];
            
        }
    }
    Array<T> &&operator+(const Array &arr){//返回右值
        Array<T> *parr = new Array<T>(this->n + arr.n);
        for(int i = 0; i < this->n; i++) {
            new(parr->data + i) T(this->data[i]);
        }
        for(int i = 0; i < arr.n;i++) {
            new(parr->data + i + this->n) T(this->data[i]);
        }
        return std::move*parr;//强行变成右值
    }
    Array<T> &operator=(Array &&arr){
        this->~Array();
        this->n = arr.n;
        this->data = arr.data;
        arr.data = nullptr;
        arr.n = 0;
        return *this;
    }
    int size(){return this->n};
    void output(){
        printf("[");
        for(int i = 0; i< this->n; i++){
            cout<< this->data[i] <<" ";
        }
        printf("]\n");
    }
    ~Array(){
        if(this->n <= 0) return;
        this->n = 0;
        delete[] this->data;
    }
private:
    T NIL;
    T *data;
    int n;
};

void print(int &x){
    cout << "lvalue : " << x <<endl;
}

void print(int &&x) {
    cout << "rvalue : " << x <<endl;
}
void func(int &x){
    print(x);
}

void func(int &&x) {
    print(std::forward<int &&>(x));
}

int main(){
    int a = 6;
    func(a++);
    func(++a);
    func(6);
    Array<Data> arr_a(5);
    Array<Data> arr_b(5);
    Array<Data> arr_c;
    arr_c = arr_a + arr_b;
    arr_c.output();
    return 0;
}
