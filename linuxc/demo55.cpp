#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');

    cout << s3.size() << endl;

    return 0;
}
