#include <iostream>

int main() {
    int ia[3][4] = {
        {1, 2, 3},
        {5, 6, 7},
        {8, 9, 10}
    };

    int (*p)[4] = ia;
    p = &ia[2];

    //*p 指向的是第二个数组的入口地址
    //**p 是指向第二个数组的第一个元素
    std::cout << **p << std::endl;

    //在c++11中，通过使用auto或者decltype，就可以尽可能的避免在数组前加一个指针类型
    //比如:int (*p)[4]
    std::cout << "=========================" << std::endl;
    for(auto m = ia; m!= ia + 3; ++m) {
        for(auto q = *m; q != *m + 4; ++q) {
            std::cout << *q << ' ';
            std::cout << std::endl;
        }
    }

    return 0;
}
