/*************************************************************************
	> File Name: 11.shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月20日 星期六 10时15分10秒
 ************************************************************************/

#include<iostream>
#include<memory>
using std::endl;
using std::cout;
using std::shared_ptr;

namespace haizei{
    template<typename T>
    class shared_ptr {
    public :
        shared_ptr(){
            this->data = nullptr;
        }
        shared_ptr(T *obj){
            this->data = obj;
            this->cnt = new int{1};
        }
        shared_ptr(const shared_ptr<T> &p){
            this->data = p.data;
            this->cnt = p.cnt;
            *(this->cnt) += 1;
        }
        template<typename Y>
        shared_ptr(const shared_ptr<Y> &p){
            p.set_ptr(this->data, this->cnt);
            *(this->cnt) += 1;
        }

        T *operator->(){
            return this->data;
        }
        template<typename Y>
        shared_ptr<T> &operator=(shared_ptr<Y> &p) {
            if(this->data){
                this->destory_ptr();
            }
            p.set_ptr(this->data,this->cnt);
            *(this->cnt) += 1;
            return *this;
        }
        shared_ptr<T> &operator=(std::nullptr_t x) {
            if(this->data) {
                this->destory_ptr();
            }
            this->data = nullptr;
            return *this;
        }
        T &operator*() const{
            return *(this->data);
        }
        void destory_ptr(){
            if(!(*(this->cnt) -= 1)) {
                delete this->data;
                delete this->cnt;
                this->data = nullptr;
                this->cnt = nullptr;
            }
            return; 
        }
        int use_count(){
            if(this->data == nullptr) return 0;
            return *(this->cnt);
        }
        template<typename Y>
        void set_ptr(Y *&obj, int *&cnt) const{
            obj = this->data;
            cnt = this->cnt;
            return ;
        }
        ~shared_ptr(){
            if(this->data == nullptr) return ;
            this->destory_ptr();
            return ;
        }
    private:
        //std::pair<T *, int> *data;
        T *data;
        int *cnt;//放地址为了都能访问同时减１
    };
}

class A {
public :
    A(){cout << " A " << endl;}
    ~A(){cout << "A si"<< endl;}
};

class B : public A {
    
};

int main(){
    B *obj = new B(); 
    haizei::shared_ptr<B> p(obj);
    haizei::shared_ptr<A> q(p), p1;
    p1 = p;
    cout << p.use_count() <<" "<< q.use_count() << endl;
    p = nullptr;
    cout << p.use_count() <<" "<< q.use_count() << endl;
    cout<< "---------" << endl;
    return 0;
}
