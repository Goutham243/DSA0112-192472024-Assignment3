
#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    Prescription(int count)
        : n(count), medicines(new string[count]) {
        cout << "Constructor called\n";
    }

    void set(int i, string m) {
        medicines[i] = m;
    }

    string get(int i) const {
        return medicines[i];
    }

    ~Prescription() {
        cout << "Destructor called\n";
        delete[] medicines;
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;  // Shallow copy

    q.set(1, "Cetirizine");

    cout << "Original: "
         << p.get(0) << " " << p.get(1) << endl;

    cout << "Copied: "
         << q.get(0) << " " << q.get(1) << endl;

    return 0;
}
