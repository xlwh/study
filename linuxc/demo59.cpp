#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string line;

    //getline() 读取一行字符串输入
    while(getline(cin, line)) {
        //xx.empty() 判断字符串是否为空
        if(line.empty()) {
            cout << "empty line" << endl;
            return 0;
        } else {
            cout << line << endl;
        }
    }
    return 0;
}
