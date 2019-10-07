#include <iostream>
using namespace std;

int main() {
	int a; 
	int b; 
	cout << "enter the first number: ";
	cin >> a; 
	cout << "enter the second number: ";
	cin >> b;
	if( a + b > 0) { 
		cout << "the sum of these two is positive." << endl; }
	else { 
		cout << "the sum of these two is negative." << endl; }
	return 0; //exit system code is read by the kernel
}
