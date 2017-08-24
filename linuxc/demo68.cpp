#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main(int argc, char ** argv) {

    string s = "my name is zhanghongbin";
    for(auto &c : s) {
        if(!isspace(c)) {
            c = 'x';
        }
    }
    cout << s << endl;
    return 0;
}
