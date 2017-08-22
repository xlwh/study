#include <iostream>
using namespace std;


int main() {
    
    extern const int bufSize = 512;

    //尝试修改const变量
    // bufSize = 20;

    cout << "bufSize:" << bufSize << endl;

    return 0;
}
