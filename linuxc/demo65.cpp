#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char **argv) {
    string s("hello, world");
    for(auto &c : s) {
        c = toupper(c);
    }
    cout << s << endl;
    return 0;
}
