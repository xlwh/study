#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int *p1;
    cout <<"p1="<< p1 << endl;
    int i = 2;
    p1 = &i;
    cout << "p1=" << p1 << endl;

    cout << &i << endl;
    cout << *p1 << endl;

    return 0;
}
