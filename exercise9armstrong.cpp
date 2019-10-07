#include <iostream>
#include <cmath>
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
    int digit_num = 0; 
	int temp = input;
	int sum	= 0;
	int num_1 = input; 
	//counts how many digits are in a nunmber
	while(temp != 0){ 
		digit_num++;
		temp = temp / 10; 
	}
	//if a number has less than 2 digits it cannot be an Armstrong num
	if(digit_num == 1 ){
		cout << input << " is not an Armstrong number." << endl;
		return 0;
	}
	else {
		//checks each digit  
		for(int i = 0; i < digit_num; i++){
			int temp_1  = num_1 % 10;
			sum = sum + pow(temp_1,digit_num);
			num_1 = num_1 / 10;
		}
		if (sum == input) { 
			cout << input << " is an Armstrong number." << endl;
		}
		else {
			cout << input << " is not an Armstrong number." << endl;
		}
	}
return 0; 
}
