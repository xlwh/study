#include <iostream>
using namespace std;

int main() {
    int r1, r2;
    cout << "Please enter tow numbers:r1 and r2" << endl;
    cin >> r1 >> r2;
    while(r1 <= r2) {
        cout << r1 << endl;
        r1++;
    }

    return 0;
}
