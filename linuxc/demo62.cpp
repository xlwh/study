#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv) {
    
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " +s2 + '\n';

    cout << s3 << endl;
    return 0;
}
