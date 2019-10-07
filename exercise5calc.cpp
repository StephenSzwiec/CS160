#include <iostream>
using namespace std;

float add( float a, float b){
	return a + b; 
}
float subtract( float a, float b) {
	return a - b;
}
float multiply( float a, float b) {
	return a * b;
}
float divide(float a, float b) {
	return a / b;
}

int main() {
	float numberOne;
	float numberTwo;
	char opInput;
	cout << "simple calculator program" << endl;
	cout << "enter first number: "; 
	cin >> numberOne; 
	while(cin.fail()) { //error handling loop
		cout << "Error: Not a number" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> numberOne; 
    }
   	cout << "enter second number: "; 
	cin >> numberTwo;  
	while(cin.fail()) { //error handling loop
		cout << "Error: Not a number" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> numberOne; 
    }
    cout << "enter operation (+, -, *, /): " << endl;
    
    cin >> opInput; 
    while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> opInput; 
    }
    while (opInput != '+' && opInput != '-' && opInput != '*' && opInput != '/') { //error handling loop
	   cout << "Error: invalid input" << endl;		cin.clear();
	   cin.ignore(256,'\n');
	   cin >> opInput;
	}
    
	switch(opInput){
		case '+':
			cout << numberOne  << " + " << numberTwo << " = " << add(numberOne,numberTwo) << endl;
			break;
		case '-':
			cout << numberOne  << " - " << numberTwo << " = " << subtract(numberOne,numberTwo) << endl;
			break;		
		case '*':
			cout << numberOne  << " * " << numberTwo << " = " << multiply(numberOne,numberTwo) << endl;
			break;		
		case '/':
			cout << numberOne  << " / " << numberTwo << " = " << divide(numberOne,numberTwo) << endl;
			break;
		default:
			cout << "Error: How did you even get here?" << endl;
	}
	return 0; //exit system code is read by the kernel
}
