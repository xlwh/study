#include <iostream>

int main() {
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for(size_t i = 0; i< rowCnt; i++) {
        for(size_t j = 0; j < colCnt; j++) {
            ia[i][j] = i * colCnt + j;
        }
    }

    for(auto &row : ia) {
        for(auto &item : row) {
            std::cout << item << std::endl;
        }
    }

    size_t cnt = 0;
    for(auto &row : ia) {
        for(auto &col : row) {
            col = cnt;
            ++cnt;
        }
    }

    std::cout << "==========================" << std::endl;
    for(const auto &row : ia) {
        for(const auto col : row) {
            std::cout << col << std::endl;
        }
    }
    return 0;
}
