// LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//<<<<<<< Updated upstream
	char drinkC, sizeC, isMember, fin;
	string drink, size, cache, strSetPrice, recieptAccumulator, name;
	double setPrice, total, Pcache, Grandtotalsales = 0;
	int totalCustomers = 1;
	for (char NewCustomer = 'y';(NewCustomer == 'y' || NewCustomer == 'Y'); totalCustomers++) {
		total = 0;
		setPrice = 0;
		Pcache = 0;
		fin = 'n';
		cout << totalCustomers << endl;

		cout << "What's your name? " << endl;
		cin >> name;

		cout << "Here's our menu!" << endl;
		cout << "Drink" << setw(15) << "Small (S)" << setw(15) << "Medium (M)" << setw(15) << "Large (L)" << setw(15) << endl;
		cout << " " << endl;
		cout << "Iced Coffee (A)" << setw(8) << "5.00" << setw(10) << "6.00" << setw(10) << "7.00" << setw(10) << endl;
		cout << "Slushy (B)" << setw(13) << "6.00" << setw(10) << "7.00" << setw(10) << "8.00" << setw(10) << endl;
		cout << "MilkShake (C)" << setw(10) << "8.00" << setw(10) << "9.00" << setw(10) << "10.00" << setw(10) << endl;

		do {

			cout << "What drink would you like? (A/B/C): " << endl;
			cin >> drinkC;
			if (cin.fail() || drinkC != 'a' && drinkC != 'A' && drinkC != 'b' && drinkC != 'B' && drinkC != 'c' && drinkC != 'C') {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid selection! Please enter a letter between A and C.\n";
				continue;
			}
			cout << "What size would you like that? (S/M/L): " << endl;
			cin >> sizeC;
			if (cin.fail() || sizeC != 's' && sizeC != 'S' && sizeC != 'm' && sizeC != 'M' && sizeC != 'l' && sizeC != 'L') {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid selection! Please enter a letter S, M, or L.\n";
				continue;
			}
			switch (drinkC) {
			case 'a':
			case 'A':
				drink = "Iced Coffee";
				setPrice = 5.00;
				break;
			case 'b':
			case 'B':
				drink = "Slushy";
				setPrice = 6.00;
				break;
			case 'c':
			case 'C':
				drink = "Milk Shake";
				setPrice = 8.00;
				break;
			default:
				cout << "Drink Error occured internally! Terminating Program." << endl;
				return 0;
			}
			switch (sizeC) {
			case 's':
			case 'S':
				size = "Small";
				setPrice += 0;
				break;
			case 'm':
			case 'M':
				size = "Medium";
				setPrice += 1.00;
				break;
			case 'l':
			case 'L':
				size = "Large";
				setPrice += 2.00;
				break;
			default:
				cout << "Size Error occured internally! Terminating Program." << endl;
				return 0;
			}

			strSetPrice = to_string(setPrice);
			strSetPrice = strSetPrice.substr(0, strSetPrice.find(".") + 3);

			recieptAccumulator += "Drink: " + drink + "\nSize: " + size + "\nPrice: $" + strSetPrice + "\n\n";
			cout << "Drink and size selected: " << drink << " " << size << endl;
			cout << "Would you like to proceed to checkout? (Y/N) :" << endl;
			cin >> fin;

			total += setPrice;
		} while (fin == 'n' || fin == 'N');

		if (fin == 'y' || fin == 'Y') {
			cout << "Are you a member? (Y/N) :" << endl;
			cin >> isMember;
			if (isMember == 'y' || isMember == 'Y') {
				total *= 0.9; // Apply 10% discount for members
			}
			double AR = total * .065;
			double FC = total * .005;
			double CM = total * .02125;

			cout << "Arkansas State Tax: 6.5% " << AR << endl;
			cout << "Faulkner County Tax: 0.5% " << FC << endl;
			cout << "Conway Municipal Tax: 2.125% " << CM << endl;

			total = total + AR + FC + CM;

			double Tip;
			char TipS;
			cout << "Tip Selection" << endl;
			cout << setprecision(3) << "A: 15% " << total * .15 << endl << "B: 20% "
				<< total * .2 << endl << "C: 25% " << total * .25 << endl << "D: custom %" << endl;
			cin >> TipS;

			if (TipS == 'a' || TipS == 'A') {
				total = total * .15 + total;
			}
			else if (TipS == 'b' || TipS == 'B') {
				total = total * .2 + total;
			}
			else if (TipS == 'c' || TipS == 'C') {
				total = total * .25 + total;
			}
			else {
				cout << "How much would you like to tip? ";
				cin >> Tip;
				total = total * (Tip / 100) + total;
			}
			cout << "Alright " << name << ", here's your receipt!" << endl;
			cout << recieptAccumulator << endl;
			cout << "Your total is: $" << fixed << setprecision(2) << total << endl;
			cout << "Thank you for your purchase!" << endl;
			cout << "Heres your rewards points: ";
			for (int i = total / 3; i >= 0; i--) {
				cout << "*";
			}
			Grandtotalsales += total;
			cout << endl;
			
		}
		else {
			cout << "Order cancelled." << endl;
		}
		cout << "New Customer? (y/n) " << endl;
		cin >> NewCustomer;
		if (NewCustomer != 'y') {
			cout << "There were " << totalCustomers << " customers today." << endl << "You made $" << Grandtotalsales << " today.";
			return 0;
		}
	}
}
