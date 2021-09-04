#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int year = 0;
	int day = 0;
	double pi = 0.0;
	string month = "";
	string name = "";

	cout << "Enter the year: ";
	cin >> year;

	//Error check
	while (cin.fail()) {
		cout << "Not a valid year, try again: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> year;
	}

	cout << "Enter the day of the month: ";
	cin >> day;

	//Error check
	while (cin.fail()) {
		cout << "Not a valid day, try again: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> day;
	}

	cout << "Enter as much of pi as you can remember: ";
	cin >> pi;

	//Error check
	while (cin.fail()) {
		cout << "Not a valid input, try again: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> pi;
	}

	cout << "Enter the month: ";
	cin >> month;
	cin.ignore();

	cout << "Enter your full name: ";
	getline(cin, name);

	// Print out all the data given by the user
	cout << month << " " << day << ", " << year << endl;
	cout << setprecision(3) << fixed << pi << endl;
	cout << setprecision(4) << fixed << pi << endl;
	cout << setprecision(5) << fixed << pi << endl;
	cout << "Welcome to CS225 " << name << "!";

	return 0;
}