#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv) {
    
    string s1 = "hello";
    string s2 = "hello";
    string s3 = s1 + s2;
    
    cout << "s1=s2:" << (s1 == s2) << endl;
    cout << "s3=" << s3 << endl;

    return 0;
}
