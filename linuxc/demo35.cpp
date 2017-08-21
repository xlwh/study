#include <iostream>

int main() {
    int sum = 0;
    int var = 1;
    while(var <= 10) {
        sum += var;
        var++;
    }
    std::cout << "The sum is:" << sum << std::endl;
    return 0;
}
