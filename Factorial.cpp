#include <iostream>
using namespace std;

int main() {
	int input;
	cout << "this program outputs the factorial of an input number." << endl;
	cout << "please enter an integer: ";
	cin >> input;
	int runner = input; //new number initialized so "input" can be used for output to user at end of program
	int factorial = 1;
	while (runner > 0){
		factorial = factorial * runner; 
		runner--;
	}
	cout << "the factorial of " << input << " is " << factorial << endl;
	return 0; //exit system code is read by the kernel
}
