#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    
    vector<int> vi;
    vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto c : vi) {
        cout << c << endl;
    }

    cout << "===============" << endl;
    string sl = "a string", *p = &sl;

    auto n = sl.size();

    n = (*p).size();
    cout << n << endl;
    n = p->size();
    cout << n << endl;

    return 0;
}
