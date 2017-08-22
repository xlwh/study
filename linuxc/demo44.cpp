#include <iostream>

int main() {
    int cnt = 1;
    int sum = 1;
    int value = 2;

    for(cnt = 1; cnt <= 10; cnt++) {
        sum *= value;
    }
    std::cout << sum << std::endl; 
    return 0;
}
