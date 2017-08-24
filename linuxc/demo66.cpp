#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s("hello world");
    decltype(s.size()) index = 0;
    for(index = 0; index < s.size(); index++) {
        if(!isspace(s[index])) {
            s[index] = toupper(s[index]);
        }
    }
    cout << s << endl;
    return 0;
}
