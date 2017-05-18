#include <iostream>
#include <cassert>
#include <string>

using namespace std;

string decode(string code) {
    string rc = "";
    string month[] = {  "Jan", "Feb", "Mar", "Apr", "May", "Jun"
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    rc += month[code[0] - 'A'] + " ";
    rc += to_string(code[1] - 'Q') + to_string(code[2] - 'Q') + " ";
    rc += to_string(code[3] - 'A' + 1 + 1995);
    return rc;
}

void test_decode() {
    assert(decode("ARZM") == "Jan 19 2008");
    cout << "passed test" << endl;
}

int main() {
    test_decode();
}
