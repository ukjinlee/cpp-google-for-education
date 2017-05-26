#include <iostream>

using namespace std;

const double kPorfitRate = 0.2;

struct Book {
    int code;
    double price;
    int onHand;
    int enrollment;
    int required;
    int theNew;
};

void inputBook(struct Book& book) {
    cout << "Please enter the book code: "; 
    cin >> book.code;
    cout << " single copy price: ";
    cin >> book.price;
    cout << " number on hand: ";
    cin >> book.onHand;
    cout << " prospective enrollment: ";
    cin >> book.enrollment;
    cout << " 1 for reqd/0 for optional: ";
    cin >> book.required;
    cout << " 1 for new/0 for used: ";
    cin >> book.theNew;
    cout << "***************************************************" << endl;
}
    
void displayBook(const struct Book& book) {
    cout << "Book: " << book.code << endl;
    cout << "Price: $" << book.price << endl;
    cout << "Inventory: " << book.onHand << endl;
    cout << "Enrollment: " << book.enrollment << endl;
    cout << endl;
    cout << "This book is " << (book.required ? "required" : "optional") << " and " << (book.theNew ? "new" : "used") << "." << endl;
    cout << "***************************************************" << endl;
}

void calculateOrder(const struct Book& book, int& order, double& cost) {
    double salesRate = 0;
    if (book.required && book.theNew)
        salesRate = 0.9;
    else if (book.required)
        salesRate = 0.65;
    else if (book.theNew)
        salesRate = 0.4;
    else
        salesRate = 0.2;
    order = book.enrollment * salesRate - book.onHand;
    cost = order * book.price;
}

void displayOrder(const int order, const double cost) {
    cout << "Need to order: " << order << endl;
    cout << "Total Cost: $" << cost << endl;
    cout << "***************************************************" << endl;
}
    
void displayTotal(const double cost) {
    cout << "Total for all orders: $" << cost << endl;
    cout << "Profit: $" << cost * kPorfitRate << endl;
    cout << "***************************************************" << endl;
}

int main() {
    double totalCost = 0;
    int goOn = 1;
    while (goOn) {
        int order = 0;
        double cost = 0;
        struct Book aBook;
        inputBook(aBook);
        displayBook(aBook);
        calculateOrder(aBook, order, cost);
        displayOrder(order, cost);
        totalCost += cost;
        cout << endl;
        cout << "Enter 1 to do another book, 0 to stop. ";
        cin >> goOn;
        cout << "***************************************************" << endl;
    }
    displayTotal(totalCost);
}