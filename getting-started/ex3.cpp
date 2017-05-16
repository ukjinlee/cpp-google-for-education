#include <iostream>
#include <cassert>

using namespace std;

void secondsToTime(int seconds, int& hour, int& min, int& sec) {
    hour = seconds / 3600;
    seconds -= 3600 * hour;
    min = seconds / 60;
    sec = seconds - 60 * min;
}

void test_secondsToTime() {
    int hour, min, sec;
    secondsToTime(3662, hour, min, sec);
    assert(hour == 1);
    assert(min == 1);
    assert(sec == 2);
    cout << "passed test" << endl;
}

int main() {
    // test_secondsToTime();
    cout << "Number of seconds: ";
    int seconds;
    cin >> seconds;
    int hour, min, sec;
    secondsToTime(seconds, hour, min, sec);
    cout << "Hours: " << hour << endl;
    cout << "Minutes: " << min << endl;
    cout << "Seconds: " << sec << endl;
}
