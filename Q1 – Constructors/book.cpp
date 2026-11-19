
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

    static int validateCopies(int c) {
        if (c < 0) {
            throw invalid_argument(
                "Number of copies cannot be negative"
            );
        }
        return c;
    }

public:
    // Default constructor
    Book() : Book("Untitled", "Unknown", 0) {
        cout << "Default constructor called\n";
    }

    // Constructor for donated book (title only)
    explicit Book(string t)
        : Book(t, "Unknown", 1) {
        cout << "Title-only constructor called\n";
    }

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(validateCopies(c)) {
        cout << "Parameterized constructor called\n";
    }

    void display() const {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Copies : " << copies << endl;
        cout << "----------------------\n";
    }
};

int main() {
    try {
        cout << "Creating empty book:\n";
        Book b1;
        b1.display();

        cout << "Creating donated book:\n";
        Book b2("C++ Programming");
        b2.display();

        cout << "Creating complete book:\n";
        Book b3("Data Structures",
                "Mark Allen", 5);
        b3.display();

        cout << "Testing negative copies:\n";
        Book b4("Java", "James", -3);
        b4.display();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
