#include <iostream>
#include <math.h>
using namespace std;


float heronMethod(double x) {
	double guess = 1;
	do {
		guess = (guess + x/guess)/2;
		cout << guess << endl; 
	} while ( fabs(guess * guess - x > 0.00000001)); 
	return guess;
}

int main() {
	cout << "This program uses Hero of Alexandria's method of finding square roots" << endl;
	cout << "enter your number: ";
	double input; 
	cin >> input; 
	double output; 
	output = heronMethod(input);
	cout << "the square root of " << input << " is: " << output << endl;
	return 0; //exit system code is read by the kernel
}
