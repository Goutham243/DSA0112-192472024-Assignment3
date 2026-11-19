
#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // Addition returns a new object
    Money operator+(const Money& other) const {
        return Money(0, paise + other.paise);
    }

    // Subtraction returns a new object
    Money operator-(const Money& other) const {
        return Money(0, paise - other.paise);
    }

    // Addition assignment modifies current object
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;
        if (amount < 0) {
            out << "-Rs ";
            amount = -amount;
        } else {
            out << "Rs ";
        }

        out << amount / 100 << "."
            << setfill('0') << setw(2) << amount % 100
            << setfill(' ');
        return out;
    }

    // Friend function for input
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        in >> rupees >> p;
        if (in) {
            m.paise = rupees * 100 + p;
        }
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;

    cout << c << '\n';
    cout << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << "Paise carry: " << x + y << '\n';

    Money d(5, 0), e(8, 50);
    cout << "Negative subtraction: " << d - e << '\n';

    d += e;
    cout << "After +=: " << d << '\n';

    cout << "Is a less than b? " << (a < b) << '\n';

    return 0;
}
