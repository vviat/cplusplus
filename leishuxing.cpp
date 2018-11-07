/*************************************************************************
	> File Name: leishuxing.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月17日 星期一 18时33分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
class people {
    public:
        void say(string word);
        void run(people & loc);
        static void is_calid_height(double height);
    private :
        static int total_num;
        string __name;
        double __birthday;
        double __height;
        double __weight;
};

int main(){

    return 0;
}
