#include <iostream>

int main() {
    
    int sum = 0, var = 10;
    while(var <= 50) {
        sum += var;
        var++;
    }

    std::cout << "The sum is:" << sum << std::endl;
    
    return 0;
}
