#include <iostream>
using namespace std;


int main(int argc, char **argv) {
    
    //void* 只能存储变量的地址，但是不知道变量的具体类型
    //所以没办法访问和操作该地址上面的变量
    //如果要操作只能赋值给有类型的指针，并进行强转
    void* p;
    cout << "p=" << p << endl;
    int a = 1;
    char b = 'c';
    p = &a;
    int *p1 = (int*)p;
    cout << *p1 <<endl;
    p = &b;
    char *c = (char*)p;
    cout << *c << endl;
    return 0;
}
