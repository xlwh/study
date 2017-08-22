#include <iostream>
using namespace std;


int main() {
    
    //引用，只是给变量起一个别名
    //指向的地址是同一个
    //所以无论是对原变量进行修改还是对引用的变量进行修改，内存中的数据都会被改变
    //这种语法特性，可以用来进行函数的传值，和传指针的意义是一样的
    int ival = 1024;
    int &refval = ival;
    cout << "ival=" << ival << ",refval=" << refval << endl;
    ival = ival + 1;
    cout << "ival=" << ival << ",refval=" << refval << endl;
    refval++;
    cout << "ival=" << ival << ",refval=" << refval << endl;
    return 0;
}
