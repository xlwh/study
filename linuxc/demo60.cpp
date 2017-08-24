#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string line;
    while(getline(cin, line)) {
        //string.size() 函数可以返回字符串的长度
        if(line.size() > 5) {
            cout << "too big" << endl;
        } else {
            cout << "ok:" << line << endl;
        }
    }

    return 0;
}
