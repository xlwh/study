#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char **argv) {

    string str("some string1");
    for(auto c : str) {
        cout << c << endl;
        if(isdigit(c)) {
            cout << "digit" << endl;
        }
    }
    return 0;
}
