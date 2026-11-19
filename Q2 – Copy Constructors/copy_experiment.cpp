
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

class Prescription {
    int n;
    string* medicines;

public:
    static int copyCount;

    Prescription(int count)
        : n(count), medicines(new string[count]) {
        for (int i = 0; i < n; i++)
            medicines[i] = "Medicine";
    }

    // Copy constructor
    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n]) {

        for (int i = 0; i < n; i++)
            medicines[i] = other.medicines[i];

        copyCount++;
        cout << "Copy constructor called" << endl;
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* temp = new string[other.n];

            for (int i = 0; i < other.n; i++)
                temp[i] = other.medicines[i];

            delete[] medicines;
            medicines = temp;
            n = other.n;
        }
        return *this;
    }

    ~Prescription() {
        delete[] medicines;
    }
};

int Prescription::copyCount = 0;

// Pass by value
void byValue(Prescription p) {
    cout << "Passed by value" << endl;
}

// Pass by reference
void byReference(const Prescription& p) {
    cout << "Passed by reference" << endl;
}

int main() {

    Prescription p(10);

    cout << "Passing by value:" << endl;
    byValue(p);

    cout << "\nPassing by reference:" << endl;
    byReference(p);

    cout << "\nTesting self assignment:" << endl;
    p = p;
    cout << "Self assignment successful" << endl;

    cout << "\nCopy performance:" << endl;

    int sizes[] = {10, 1000, 100000};

    for (int size : sizes) {
        Prescription original(size);

        auto start = high_resolution_clock::now();

        Prescription copy(original);

        auto stop = high_resolution_clock::now();

        auto duration =
            duration_cast<microseconds>(stop - start);

        cout << size << " medicines: "
             << duration.count() << " microseconds"
             << endl;
    }

    cout << "\nTotal copies: "
         << Prescription::copyCount << endl;

    return 0;
}
