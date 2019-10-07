#include <string>
#include <iostream>
using namespace std;

int main () {
	string fName, lName; 
	cout << "Enter your first name: ";
	getline(cin,fName);
	cout << "Enter your last name: ";
	getline(cin,lName);
	if (fName[0] == 'A' || fName[0] == 'a') {
		cout << "Yes." << endl;
	}
	else {
		cout << "No" << endl;
	}
	if (fName > lName) {
		cout << "First name is greater" << endl;
	}
	else if (fName < lName) {
		cout << "Last name is greater" << endl;
	}
	else {
		cout << "They are equal" << endl;
	}
	return 0; 
}
