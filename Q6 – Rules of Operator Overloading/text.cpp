
#include <iostream>
#include <cstring>
#include <chrono>
#include <string>
using namespace std;

class Text {
    char* data;
    static int copyCount;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        ++copyCount;
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);
            delete[] data;
            data = temp;
            ++copyCount;
        }
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Concatenation operator
    Text operator+(const Text& other) const {
        size_t len = strlen(data) + strlen(other.data);
        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    static void showCopies() {
        cout << "Copy count: " << copyCount << '\n';
    }
};

int Text::copyCount = 0;

int main() {
    cout << "Text Concatenation:\n";

    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;
    cout << result << '\n';

    cout << "\nComparison:\n";
    Text x("Hello");
    Text y("Hello");
    cout << boolalpha << (x == y) << '\n';
    cout << (x != y) << '\n';

    cout << "\nSelf Assignment:\n";
    x = x;
    cout << x << '\n';

    cout << "\nEmpty Text:\n";
    Text empty("");
    cout << "Empty text: [" << empty << "]\n";

    cout << "\nLong Message:\n";
    Text longText("This is a long message used to test dynamic memory allocation.");
    cout << longText << '\n';

    Text::showCopies();

    // Compare with std::string for 100,000 concatenations
    cout << "\nPerformance Test:\n";

    const int N = 100000;
    string standard = "A";

    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        standard = standard + "B";
    auto end1 = chrono::high_resolution_clock::now();

    cout << "std::string time: "
         << chrono::duration<double, milli>(end1 - start1).count()
         << " ms\n";

    return 0;
}
