
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <chrono>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        if (seconds == 60) {
            seconds = 0;
            ++minutes;
        }
        if (minutes == 60) {
            minutes = 0;
            ++hours;
        }
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    bool operator==(const Time& other) const {
        return hours == other.hours &&
               minutes == other.minutes &&
               seconds == other.seconds;
    }

    bool operator<(const Time& other) const {
        if (hours != other.hours)
            return hours < other.hours;
        if (minutes != other.minutes)
            return minutes < other.minutes;
        return seconds < other.seconds;
    }

    void display() const {
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << ":";
        if (seconds < 10) cout << "0";
        cout << seconds << '\n';
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(vector<string> t) : tracks(t) {}

    string& operator[](int index) {
        if (index < 0 || index >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");
        return tracks[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");
        return tracks[index];
    }

    int size() const {
        return (int)tracks.size();
    }
};

int main() {
    cout << "Increment Operators:\n";

    Time t(0, 0, 5);
    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();
    cout << "t = ";
    t.display();

    cout << "\nTime Comparison:\n";
    cout << boolalpha << (a < b) << '\n';
    cout << (a == b) << '\n';

    cout << "\nHour Rollover:\n";
    Time rollover(0, 59, 59);
    ++rollover;
    rollover.display();

    cout << "\nPlaylist:\n";
    Playlist p({"Song A", "Song B", "Song C"});

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << '\n';

    try {
        cout << p[-1] << '\n';
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
