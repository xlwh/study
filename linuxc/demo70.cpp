#include <iostream>
#include <vector>
using namespace std;

int main() {
    //vector的初始化方式
    vector<int> v1;
    vector<int> v2(2);
    vector<int> v3(10, 3);
    //vector<int> v4 = 4;
    vector<int> v5 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v6{3, 4, 6, 8, 9, 2};

    v6.push_back(100);
    for(auto i : v6) {
        cout << i << endl;
    }
    return 0;
}
