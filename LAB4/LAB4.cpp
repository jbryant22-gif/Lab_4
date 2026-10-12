// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{

	char drinkC, sizeC, isMember, f1n;
	string drink, size, cache, strSetPrice, recieptAccumulator, name, food1, food2, food3, foodaccum;
	double setPrice, total, Pcache, Grandtotalsales = 0, foodsm1, foodme1, foodlg1
		, foodsm2, foodme2, foodlg2, foodsm3, foodme3, foodlg3;
	int totalCustomers = 1, foodamount1 = 50, foodamount2 = 50, foodamount3 = 50, count1 = 0, count2 = 0, count3 = 0;

	ofstream reciept_fout;
	ifstream Bacon_Cheeseburger_fin;

	Bacon_Cheeseburger_fin.open("Bacon_Cheeseburger.txt");

	if (Bacon_Cheeseburger_fin.is_open()) {
		cout << "File Opened\n" << endl;
	}
	else {
		cout << "File Not Opened\n" << endl;
	}

	Bacon_Cheeseburger_fin >> food1;
	Bacon_Cheeseburger_fin >> foodsm1;
	Bacon_Cheeseburger_fin >> foodme1;
	Bacon_Cheeseburger_fin >> foodlg1;
	Bacon_Cheeseburger_fin >> food2;
	Bacon_Cheeseburger_fin >> foodsm2;
	Bacon_Cheeseburger_fin >> foodme2;
	Bacon_Cheeseburger_fin >> foodlg2;
	Bacon_Cheeseburger_fin >> food3;
	Bacon_Cheeseburger_fin >> foodsm3;
	Bacon_Cheeseburger_fin >> foodme3;
	Bacon_Cheeseburger_fin >> foodlg3;

	Bacon_Cheeseburger_fin.close();

	for (char NewCustomer = 'y';(NewCustomer == 'y' || NewCustomer == 'Y'); totalCustomers++) {
		total = 0;
		setPrice = 0;
		Pcache = 0;
		f1n = 'n';
		cout << totalCustomers << endl;

		cout << "What's your name? " << endl;
		cin >> name;

		cout << "Here's our menu!" << endl;
		cout << "Food" << setw(30) << "Small (S) " << setw(10) << "Medium (M) " << setw(10) << "Large (L) " << setw(10) << endl;
		cout << " " << endl;
		cout << "Bacon Cheeseburger (A)" << setw(14) << foodsm1 << setw(10) << foodme1 << setw(10) << foodlg1 << setw(10) << endl;
		cout << "Loaded Cheesy Fries (B)" << setw(13) << foodsm2 << setw(10) << foodme2 << setw(10) << foodlg2 << setw(10) << endl;
		cout << "Ceasar Salad (C)" << setw(20) << foodsm3 << setw(10) << foodme3 << setw(10) << foodlg3 << setw(10) << endl;

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
				drink = "Bacon Cheeseburger";
				setPrice = 4.99;
				break;
			case 'b':
			case 'B':
				drink = "Loaded Cheesy Fries";
				setPrice = 5.99;
				break;
			case 'c':
			case 'C':
				drink = "Ceasar Salad";
				setPrice = 3.99;
				break;
			default:
				cout << "Food Error occured internally! Terminating Program." << endl;
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

			recieptAccumulator += "Food: " + drink + "\nSize: " + size + "\nPrice: $" + strSetPrice + "\n\n";
			cout << "Drink and size selected: " << drink << " " << size << endl;
			cout << "Would you like to proceed to checkout? (Y/N) :" << endl;
			cin >> f1n;
			if (drink == "Bacon Cheeseburger") {
				foodamount1 -= 1;
				count1 += 1;
			}
			else if (drink == "Loaded Cheesy Fries") {
				foodamount2 -= 1;
				count2 += 1;
			}
			else {
				foodamount3 -= 1;
				count2 += 1;
			}



			total += setPrice;
		} while (f1n == 'n' || f1n == 'N');

		if (f1n == 'y' || f1n == 'Y') {
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
			reciept_fout.open("reciept_fout");
			cout << recieptAccumulator << endl;
			cout << "Your total is: $" << fixed << setprecision(2) << total << endl;
			cout << "Thank you for your purchase!" << endl;
			cout << "Heres your rewards points: ";
			reciept_fout << recieptAccumulator << endl;
			reciept_fout << "Your total is: $" << fixed << setprecision(2) << total << endl;
			reciept_fout << "Thank you for your purchase!" << endl;
			reciept_fout << "Heres your rewards points: ";
			for (int i = total / 3; i >= 0; i--) {
				cout << "*";
				reciept_fout << "*";
			}
			Grandtotalsales += total;
			cout << endl;
			reciept_fout.close();

		}
		else {
			cout << "Order cancelled." << endl;
		}
		cout << "New Customer? (y/n) " << endl;
		cin >> NewCustomer;
		if (NewCustomer != 'y') {
			cout << "There were " << totalCustomers << " customers today." << endl << "You made $" << Grandtotalsales << " today." << endl;
			cout << "There were 50 Bacon Cheeseburgers, and now there are " << foodamount1 << ". There were " << count1 << " sold." << endl;
			cout << "There were 50 Loaded Cheesy Fries, and now there are " << foodamount2 << ". There were " << count2 << " sold." << endl;
			cout << "There were 50 Ceasar Salads, and now there are " << foodamount3 << ". There were " << count3 << " sold." << endl;
			return 0;
		}
	}
}
