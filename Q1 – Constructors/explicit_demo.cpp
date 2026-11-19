
#include <iostream>
#include <string>
using namespace std;

class Book {
public:

#ifdef SHOW_WITHOUT_EXPLICIT
    Book(string title) {
#else
    explicit Book(string title) {
#endif
        cout << "Book created: " << title << endl;
    }
};

void displayBook(Book b) {
    cout << "Displaying book successfully" << endl;
}

int main() {

    // Implicit conversion
    displayBook(string("C++ Programming"));

    return 0;
}
