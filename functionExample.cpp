#include <iostream>
using namespace std;
void firstFunction(); //declaring functions before main
void secondFunction(); //this is an example of function prototyping

int main() {
	cout << "I am inside the main function." << endl;
	firstFunction();
	cout << thirdFunction();
	
	return 0; //exit system code is read by the kernel
}


void secondFunction() {
	cout << "I am inside the second function." << endl;
	}
	
void firstFunction() {
	int num1,num2; //declaring variables within this function is example of variable redunancy; this should have been done in main 
	cout << "I am inside the first function." << endl;
	cout << "Please input two integers to add them." << endl;
	cout << "input first number: ";
	cin >> num1; 
	cout << "input second number: ";
	cin >> num2; 
	cout << "sum of two numbers = " << num1 + num2 << endl;
	secondFunction(); //typically, do not put functions inside of functions
	//void means it does not return any value to main 
}
double thirdFunction() { 
	double num1,num2;
	cout << "I am inside the third function." << endl;
	cout << "Please input two floating point numbers to add them." << endl;
	cout << "input first number: ";
	cin >> num1; 
	cout << "input second number: ";
	cin >> num2; 
	public double answer;
	return answer; 
}
