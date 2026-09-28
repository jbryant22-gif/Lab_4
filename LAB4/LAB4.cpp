// LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    char drinkC, sizeC, isMember;
    string drink, size;
    int setPrice;
    setPrice = 5;


    cout << "Here's our menu!" << endl;
    cout << "Drink" << setw(15) << "Small (S)" << setw(15) << "Medium (M)" << setw(15) << "Large (L)" << setw(15) << endl;
    cout << " " << endl;
    cout << "Iced Coffee (A)" << setw(8) << "5.00" << setw(10) << "6.00" << setw(10) << "7.00" << setw(10) << endl;
    cout << "Slushy (B)" << setw(13) << "6.00" << setw(10) << "7.00" << setw(10) << "8.00" << setw(10) << endl;
    cout << "MilkShake (C)" << setw(10) << "8.00" << setw(10) << "9.00" << setw(10) << "10.00" << setw(10) << endl;


    cout << "What drink would you like? (A/B/C): " << endl;
    cin >> drinkC;

    cout << "What size would you like that? (S/M/L): " << endl;
    cin >> sizeC;

    cout << "Are you a member? (y/n)" << endl;
    cin >> isMember;


    if (drinkC == 'a' || drinkC == 'A') {
        drink = "Iced Coffee";
    }
    else if (drinkC == 'b' || drinkC == 'B') {
        drink = "Slushy";
        setPrice = setPrice + 1;
    }
    else if (drinkC == 'c' || drinkC == 'C') {
        drink = "Milk Shake";
        setPrice = setPrice + 3;
    }
    else {
        cout << "Drink Error occured internally! Terminating Program." << endl;
    }

    if (sizeC == 's' || sizeC == 'S') {
        size = "Small";
    }
    else if (sizeC == 'm' || sizeC == 'M') {
        size = "Medium";
        setPrice = setPrice + 1;
    }
    else if (sizeC == 'l' || sizeC == 'L') {
        size = "Large";
        setPrice = setPrice + 2;
    }
    else {
        cout << "Size Error occured internally! Terminating Program." << endl;
    }
    
    if (isMember == 'y' || isMember == 'Y') {
        setPrice = setPrice * 0.9;
    }

    cout << "drink: "<< size << " " << drink << setw(10) << fixed << setprecision(2) << "Price ($): " << setPrice << endl;




    return 0;
}