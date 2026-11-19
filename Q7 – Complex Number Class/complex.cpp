
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <complex>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with real part
    Complex(double r) : real(r), imag(0) {}

    // Constructor with real and imaginary parts
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw runtime_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        return abs(real - c.real) < 1e-9 &&
               abs(imag - c.imag) < 1e-9;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + j" << c.imag;
        else
            out << " - j" << abs(c.imag);
        return out;
    }
};

int main() {
    try {
        cout << "AC Circuit Impedance Calculator\n\n";

        // Resistor, inductor and capacitor impedances
        Complex R(10, 0);
        Complex L(0, 5);
        Complex C(0, -5);

        // Series RLC impedance
        Complex series = R + L + C;

        cout << "Series Impedance: " << series << '\n';
        cout << "Series Magnitude: " << series.magnitude() << '\n';

        // Parallel circuit impedance
        Complex Z1(10, 5);
        Complex Z2(10, -5);

        Complex parallel = (Z1 * Z2) / (Z1 + Z2);

        cout << "\nParallel Impedance: " << parallel << '\n';
        cout << "Parallel Magnitude: " << parallel.magnitude() << '\n';

        // Other operator tests
        cout << "\nAddition: " << (Z1 + Z2) << '\n';
        cout << "Subtraction: " << (Z1 - Z2) << '\n';
        cout << "Multiplication: " << (Z1 * Z2) << '\n';
        cout << boolalpha;
        cout << "Equality: " << (Z1 == Z2) << '\n';

        // Division by zero test
        Complex zero(0, 0);

        cout << "\nZero Division Test:\n";
        Complex result = Z1 / zero;
        cout << result << '\n';

    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
