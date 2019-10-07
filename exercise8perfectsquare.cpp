#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int input, sqroot, check;
	bool done = false; 
	cout << "Please enter a perfect square: ";
	cin >> input; 
	while (cin.fail()){
		cout << "Please enter a postive integer: ";
		cin >> input;
	}
	do {
		sqroot = sqrt(input); 
		check = int(pow(sqroot,2)); 
		if (check == input){ 
		cout <<"Correct. It is a perfect square."<<endl;
		done = true;
		}
		else {
			cout << "Please enter a perfect square: ";
			cin >> input;
		}
	} 
	while (done == false);
	return 0;
}
