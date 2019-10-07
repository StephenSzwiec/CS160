#include <iostream>
using namespace std;

int main() {
	int input;
	int counter = 0;
	cout << "this program outputs factors of an input number." << endl;
	cout << "please enter an integer: ";
	cin >> input;
	
	cout << "the factors of " << input << " using a while loop are:" << endl;
	while(counter != input) {
		counter++; 
		if( input % counter == 0) {
			cout << counter << endl;
		}
	}
	
	cout << "the factors of " << input << " using a for loop are:" << endl;
	for (int i = 1; i <= input; i++)
	{
		if( input % i == 0) {
			cout << i << endl;
		}
	}
	
	cout << "the factors of " << input << " using a do-while loop are:" << endl;
	counter = 0; // reinitialize global counter variable
	do {
		counter++; 
		if( input % counter == 0) {
			cout << counter << endl;
			}
		} while(counter != input);

	return 0; //exit system code is read by the kernel
}
