#include <iostream>
using namespace std;
// hello world program example

int main() {
	short age; //initialize integer age
	cout << "Enjoy yourself with C++!" << endl; //best pratice to use endl 
	cout << "This is my second CS160 class \n"; //'\n' also works 
	cout << "what is your age? : ";
	cin >> age; 
	cout << "Your age is " << age <<".";
	cout << " Thank you. Exiting..." << endl;
	return 0; //exit system code is read by the kernel
}
