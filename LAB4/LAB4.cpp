// LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string foodName;
    string cashNotes;
    int itemQuantity;
    char itemCode;
    double unitPrice;
    char isMember;

    cout << "What food did you get? " << endl;
    getline(cin, foodName);
    cin.clear();

    cout << "What is the item Code?" << endl;
    cin >> itemCode;
    cin.clear();

    cout << "How many did you get? " << endl;
    cin >> itemQuantity;
    cin.clear();

    cout << "What is the cost per unit? " << endl;
    cin >> unitPrice;
    cin.clear();

    cout << "Are you a member? (y/n)" << endl;
    cin >> isMember;
    cin.clear();

    if (isMember == 'y' || isMember == 'Y') {
        unitPrice = unitPrice * 0.9;
    }

    cout << "Any notes from the Cashier? " << endl;
    cin.ignore();
    getline(cin, cashNotes);

    cout << "item: " << foodName << setw(3) << "   QTY: " << itemQuantity << setw(10) << fixed << setprecision(2) << "   total price: $" << unitPrice * itemQuantity << endl;
    cout << "Item Code: " << itemCode << endl;
    cout << "Is Member: " << isMember << endl;
    cout << "Notes from the Cashier: " << cashNotes << endl;

    return 0;
}