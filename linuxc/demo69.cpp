#include <string>
#include <cctype>
#include <iostream>
using namespace std;


int main() {
    string s = "my,name,is,zhang,hong,bin";
    for(auto &c : s) {
        if(ispunct(c)) {
            c = ' ';
        }
    }

    cout << s << endl;
    return 0;
}
