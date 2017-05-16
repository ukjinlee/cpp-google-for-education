#include <iostream>
#include <cassert>

using namespace std;

double chirpsToTemperature(int chirps) {
    return (chirps + 40) / 4.0;
}

void test_chirpsToTemperature() {
    assert(chirpsToTemperature(120) == 40.0);
    cout << "passed test_solution" << endl;
}

int main() {
    // test_chirpsToTemperature();
    cout << "Number of chirps: ";
    int chirps;
    cin >> chirps;
    cout << "The temperature is: " << chirpsToTemperature(chirps) << " degrees." << endl;
}
