
#include <iostream>
#include <string>
using namespace std;

class Event {
    string name;
    int rows, seats;
    char** seatMap;
    int booked;

public:
    // Dynamic constructor
    Event(string n, int r, int s)
        : name(n), rows(r), seats(s),
          seatMap(nullptr), booked(0) {

        cout << "Constructor: " << name << endl;

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked: "
                 << r << "," << s << endl;
        }
        else {
            cout << "Invalid or occupied seat" << endl;
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'X') {

            seatMap[r][s] = 'O';
            booked--;
            cout << "Seat cancelled: "
                 << r << "," << s << endl;
        }
        else {
            cout << "Seat is not booked" << endl;
        }
    }

    // Display seat map
    void display() const {
        cout << "\nSeat Map: " << name << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";

            cout << endl;
        }
    }

    // Destructor
    ~Event() {
        cout << "Destructor: " << name
             << " | Booked seats: " << booked << endl;

        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];

        delete[] seatMap;
    }
};

int main() {

    cout << "--- Stack Object ---\n";

    Event e1("Stack Event", 2, 3);
    e1.bookSeat(0, 0);
    e1.bookSeat(1, 1);
    e1.cancelSeat(0, 0);
    e1.display();

    cout << "\n--- Block Object ---\n";

    {
        Event e2("Block Event", 2, 2);
        e2.bookSeat(0, 1);
    }

    cout << "\n--- Heap Object ---\n";

    Event* e3 = new Event("Heap Event", 3, 3);
    e3->bookSeat(1, 1);
    delete e3;

    cout << "\n--- Zero Rows Test ---\n";

    Event e4("Empty Event", 0, 5);

    cout << "\n--- Memory Calculation ---\n";

    int sizes[][2] = {
        {10, 20},
        {100, 200},
        {1000, 2000}
    };

    for (auto& size : sizes) {
        long long memory =
            (long long)size[0] * size[1] * sizeof(char)
            + (long long)size[0] * sizeof(char*);

        cout << size[0] << " x " << size[1]
             << " : " << memory << " bytes" << endl;
    }

    return 0;
}
