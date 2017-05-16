#include <iostream>
#include <cassert>

using namespace std;

double computeFinalGrade(int assignment, int midterm, int finalTerm, int sectionGrade) {
    return assignment / 4.0 * 0.4 + midterm * 0.15 + finalTerm * 0.35 + sectionGrade * 0.1;
}

int getInput(string str) {
    cout << str;
    int input;
    cin >> input;
    return input;
}

void test_computeFinalGrade() {
    assert(computeFinalGrade(75+85+82+94, 81, 89, 100) == 86.9);
    cout << "passed test_solution" << endl;
}

int main() {
    // test_computeFinalGrade();
    int assignment = getInput("Enter the score for the first assignment. ");
    assignment += getInput("Enter the score for the second assignment. ");
    assignment += getInput("Enter the score for the third assignment. ");
    assignment += getInput("Enter the score for the fourth assignment. ");
    int midterm = getInput("Enter the score for the midterm. ");
    int finalTerm = getInput("Enter the score for the final. ");
    int sectionGrade = getInput("Enter the score for the section grade. ");
    cout << "The final grade is: " << computeFinalGrade(assignment, midterm, finalTerm, sectionGrade) << endl;
}
