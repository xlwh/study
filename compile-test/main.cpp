#include <iostream>
#include "add.h"
#include "sub.h"

using namespace std;


int main() {
    int a = 10;
    int b = 5;

    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
}
