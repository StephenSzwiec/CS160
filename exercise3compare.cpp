#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "This program compares three interger inputs and prints them in ascending order." << endl;
	cout << "Please enter the first number: ";
	//this allows for input of digits while throwing errors if the input is not an integer
	cin >> a; 
	while(cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> a;
    }
    cout << "using " << a << endl;
    cout << "Please enter the second number: "; 
    cin >> b; 
	while(cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> b;
    }
    cout << "using " << b << endl;
    cout << "Please enter the third number: "; 
    cin >> c; 
	while(cin.fail()) {
		cout << "Error" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> c;
    }
    cout << "using " << c << endl;
    
	cout << "Output: " << endl;

    if ( a > b && a >= c ) {
		cout << a << endl;
		if ( b > c ) {
			cout << b << endl;
			cout << c << endl;
		}
		else {
			cout << c << endl;
			cout << b << endl;
		}
	}
	else if ( b > a && b > c) {
		cout << b << endl;
		if ( a > c ) {
			cout << a << endl;
			cout << c << endl;
		}
		else {
			cout << c << endl;
			cout << a << endl;
		}
	}
	else if ( a = b ) {
		if ( c > a ) {
			cout << c << endl;
			cout << a << endl;
			cout << b << endl;
		}
		else {
			cout << a << endl; 
			cout << b << endl;
			cout << c << endl;
		}
	}
	else {
		cout << c << endl;
		if ( a > b ) {
			cout << a << endl;
			cout << b << endl; 
		}
		else {
			cout << b << endl;
			cout << a << endl;
		}
	}
	return 0; //exit system code is read by the kernel
}
