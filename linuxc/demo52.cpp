#include <iostream>
#include <string>

using namespace std;

int main() {

    struct Sales_data {
        std::string bookNO;   //书籍的ISBN
        unsigned units_sold = 0;  //销售量
        double revenue = 0.0;     //书籍单价
    };
    
    struct Sales_data s1;
    cout << "Please enter:" << endl;
    cin >> s1.bookNO >> s1.units_sold >> s1.revenue;
    cout << s1.bookNO << endl;
    return 0;
}
