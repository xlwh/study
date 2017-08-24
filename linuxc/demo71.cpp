#include <iostream>

using namespace std;

int main() {
    
    int arr[10] = {};

    for(int i = 0; i < sizeof(arr); i++) {
        arr[i] = i;
    }

    for(auto c : arr) {
        cout << c << endl;
    }
    
    return 0;
}
