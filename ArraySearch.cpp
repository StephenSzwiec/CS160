/* 
 * 
 * 
 * 
 * */

#include <iostream>
using namespace std;

int main(){
	int arrInput = 0; 
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
	int a[arrInput];
	cout << "created a list with length of " << sizeof(a)/sizeof(a[0]) << "." << endl;
	
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
	
	
	bool isThere = false;
	int counter = 0;
 
	int input;
	cout << "search for the number in list: ";
	cin >> input;
	while(cin.fail()) {     //error handling loop
		cout << "Error: invalid input! please try again: " << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> input;
	}
	int value = input;

	for (int i = 0; i < 5; i++){
		//at each element of the array, it checks if value is equal to that element
		if (a[i] == value) {
			isThere = true; // makes sure if it found the number at least once then it doesn't need to say it didn't find it
			counter++;
			cout << "Found " << value << " at index: " << i << endl;
		}
	}
	
	//check the boolean, decide if number was found
	if (isThere == false) {
		cout << value << " was never found." << endl;
	}
	else {
		cout << "found " << value << " in the array " << counter << " times" << endl;
	}
return 0;
}
