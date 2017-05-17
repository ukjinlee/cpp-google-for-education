#include <iostream>
#include <cassert>

using namespace std;

int reverse(int n) {
    int reverseNum = 0;
    int remainder;
    while (n > 0) {
        remainder = n % 10;
        reverseNum = reverseNum * 10 + remainder;
        n /= 10;
    }
    return reverseNum;
}

void test_reverse() {
    assert(reverse(901) == 109);
    assert(reverse(297) == 792);
    cout << "passed test" << endl;
}

int main() {
    // test_reverse();
    cout << "input number: ";
    int input;
    cin >> input;
    int reverseNum = reverse(input);
    cout << "reverse it: " << reverseNum << endl;
    int subtract = input - reverseNum;
    cout << "subtract: " << input << " - " << reverseNum << " = " << subtract << endl;
    reverseNum = reverse(subtract);
    cout << "reverse it: " << reverseNum << endl;
    cout << "add: " << reverseNum << " + " << subtract << " = " << reverseNum + subtract << endl;
}
