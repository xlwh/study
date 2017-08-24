#include <iostream>


int main() {
    int ia[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    size_t cnt = 0;
    for(auto &row : ia) {
        for(auto &col : row) {
            col = cnt;
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
