#include <iostream>
using namespace std;

int main(){
	cout << "Please input a positive integer: " << endl;
	int input = 0; 
	cin >> input; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> input; 
    }
    while(input < 1) { //error handling loop
   		cout << "Error: please input positive integers only" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> input; 
    }
    int rows = input; 
	int numberElements = 0;
//generate the number of elements needed as a function of rows 
	for(int i = 1; i <= rows; i++){ 
		numberElements = i * i - numberElements;
	}
//number of elements defines the new array size
	long int elements[numberElements];
//populate the new array
//zero just isn't part of the fibonacci set, but here it is 
	elements[0] = 0; 
//if there is more than the one row, initialize the first two values of fibonacci's sequence
	if (sizeof(elements)/sizeof(*elements) > 1){ 
		elements[1] = 1;
		elements[2] = 1;
	}
//if we actually need to compute fibonacci's sequence from 1 and 1, we start here
	if (sizeof(elements)/sizeof(*elements) > 3){ 
		for(unsigned int j = 3; j < sizeof(elements)/sizeof(*elements); j++){
//compute fibonacci elements for size of array
			elements[j] = elements[j-1] + elements[j-2];
		}
	}
//fibonacci array has been constructed to proper length 
//loops to print the contents of the array into a triangle
	cout << "fibonacci sequence arranged into " << rows << " rows: " << endl; 
	int count = 0; 
	for (unsigned int r = 0; r < input; r++){
		for (unsigned int e = 0; e <= r; e++){
			cout << elements[count] << "\t";
			count++; 
        }
        cout << endl;
	}
	return 0;
}
	
