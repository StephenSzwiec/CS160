#include <iostream>
using namespace std;

int main() {
	int a;
	cout << "enter the user grade: ";
	cin >> a; 
	if (a >= 90) 
       { cout << "Your grade is an A." << endl; 
    }
	else if (a >= 80 && a < 90) {
		cout << "Your grade is a B." << endl;
	}
	else if (a >= 70 && a < 80) {
		cout << "Your grade is a C." << endl;
	}
	else if (a >= 60 && a < 70) {
		cout << "Your grade is a D." << endl;
	}
	else if (a < 60) {
		cout << "Your grade is an F." << endl;
	}
	else {
		cout << "Please enter a valid number." << endl; 
	}
	return 0; //exit system code is read by the kernel
}
