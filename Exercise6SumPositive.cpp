#include <iostream>
using namespace std;

//function of sum_positive only adds positive values 
void sum_positive(int afunc[], int size) {
	int sum = 0; 
	
	for (int i = 0; i < size; i++) {
			cout <<afunc[i] << endl; 
	}
	for (int i = 0; i < size; i++) {
		if (afunc[i] > 0) {
			sum = sum + afunc[i];
		}
	}
	
	cout << "The total of positive values is: " << sum << endl; 
}

int main(){

	int arrInput = 0; 
	//loop to take length of array
	cout << "Please enter list size: ";
	cin >> arrInput; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> arrInput; 
	}
	while(arrInput <= 0) {
                cout << "Error: please enter positive numbers only: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> arrInput;
	}
	int a[arrInput]; //creates array of length provided by user
	
	cout << "created a list with length of " << sizeof(a)/sizeof(a[0]) << "." << endl;
	
	//loop to take values from the user
	for (int i = 0; i < arrInput; i++) {
		cout << "please enter value for element " << i + 1 << " of the list: ";
		cin >> a[i];
		while(cin.fail()) {	//error handling loop
			cout << "Error: invalid input" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> a[i];
		}
	}
	
	//call sum positive 
	sum_positive(a, arrInput);

	return 0; 
}
