#include <string>
#include <iostream>
#include <cctype>
using namespace std;


int main() {
 
    //数组的名字指向的就是数组元素的首地址
    string nums[] = {"one", "two", "three"};
    string *p = &nums[0];
    string *t = nums;
    cout << "*p=" << *p << endl;
    cout << "*t=" << *t << endl;
    cout << "p=" << p << endl;
    cout << "t=" << t << endl;

    //先++再进行赋值的操作，这样可以符合预期的输出的是2
    cout << *(++p) << endl;

    string *be = begin(nums);
    string *en = end(nums);
    while(be != en ) {
        cout << *(++be) << endl;
    }
    return 0;
}
