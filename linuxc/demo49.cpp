#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    cout << "pi=" << pi << endl;
    cout << "ppi=" << ppi << endl;

    cout << "*pi=" << *pi << endl;
    cout << "**ppi=" << *ppi << endl;

    return 0;
}
