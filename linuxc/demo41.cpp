#include <iostream>

int main() {
    
    int sum =0, var = 0;
    while(std::cin >> var) {
        sum += var;
        if(var == -1) {
            break;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
