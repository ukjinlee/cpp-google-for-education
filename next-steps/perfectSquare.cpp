#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool isPerfectSquare(double n) {
    double sqroot = sqrt(n);
    return sqroot == trunc(sqroot);
}

bool isSumOfSeries(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
        if (sum == n) {
            return true;
        } else if (n < sum) {
            return false;
        }
    }
    return false;
}

void test_isPerfectSquare() {
    assert(isPerfectSquare(36) == true);
    assert(isPerfectSquare(38) == false);
    cout << "passed test_isPerfectSquare" << endl;
}

void test_isSumOfSeries() {
    assert(isSumOfSeries(36) == true);
    assert(isSumOfSeries(38) == false);
    cout << "passed test_isSumOfSeries" << endl;
}

int main() {
    // test_isPerfectSquare();
    // test_isSumOfSeries();
    int i = 1;
    int perfectSquare = 0;
    while (perfectSquare < 32767) {
        if (isPerfectSquare(i) && isSumOfSeries(i)) {
            perfectSquare = i;
            cout << "perfectSquare: " << perfectSquare << endl;
        }
        i++;
    }
}