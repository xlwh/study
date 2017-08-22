#include <iostream>
using namespace std;

//以下的语法只有在c++11才能支持
//需要安装gcc 4.8
int main(int argc, char **argv) {
    int v1 = 0;
    int v2 = {1};
    int v3{3};
    int v4(4);

    cout << v1 << " " << v2 << " " << v3 << " " << v4 << endl;

    return 0;
}
