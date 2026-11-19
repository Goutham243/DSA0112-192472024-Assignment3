
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;

public:
    Book(string t) : title(t) {
        cout << "Book created: " << title << endl;
    }
};

int main() {

    Book books[3];

    return 0;
}
