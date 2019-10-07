#include <iostream>
using namespace std;

int main() {
	int a; 
	int b; 
	cout << "enter the first number: ";
	cin >> a; 
	cout << "enter the second number: ";
	cin >> b;
	if( a - b > 0) { 
		cout << a << " is greater than " << b << endl; }
	else if (a - b < 0){ 
		cout << b << " is greater than " << a << endl; }
	else {
		cout << a << " is equal to " << b << endl; }
	return 0; //exit system code is read by the kernel
}
