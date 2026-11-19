
#include <iostream>
using namespace std;

class Demo {
    int x;
    int y;

public:
    Demo() : y(20), x(10) {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int main() {
    Demo d;
    return 0;
}
