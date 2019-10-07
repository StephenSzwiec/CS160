#include <iostream>
#include <iomanip> //setw()

using namespace std;

int main(){

	//greet the user 
	cout << "Matrix calculator: enter two matrices to perform addition, subtraction,  and multiplication on them." << endl;
	//take in values for matrix A, initialize array, and populate with user input 
	cout << "Enter values for first matrix..." << endl;
	int rowInputA, colInputA = 0;
	cout << "enter a value between 1 and 10 for rows: ";
	cin >> rowInputA; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInputA; 
	}
	while( rowInputA > 10 || rowInputA<= 0) {
		cout << "Error: enter rows between 1 and 10: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInputA;
	}
	cout << "enter a value between 1 and 10 for columns: ";
	cin >> colInputA; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInputA; 
	}
	while( colInputA > 10 || colInputA <= 0) {
		cout << "Error: enter rows between 1 and 10: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInputA;
	}
	float matrixA [rowInputA][colInputA];
	
	for (int row = 0; row < rowInputA; row++) {
		for ( int col = 0; col < colInputA; col++) {
			cout << "please enter value for (" << row + 1 << "," << col + 1 <<") :";
			cin >> matrixA[row][col];
			while(cin.fail()) {	//error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> matrixA[row][col];
			}
		}
	}
	cout << "Created matrix 1 with values: " << endl;
	for (int row = 0; row < rowInputA; row++) {
		for (int col = 0; col < colInputA; col++) {
			cout << setw(4) << matrixA [row][col];
		}
		cout << endl;
	}
	
	//perform the same as above, but with matrix B, saving values for row and column input for error checking
	int rowInputB, colInputB = 0;
	cout << "Enter values for second matrix..." << endl;
	cout << "enter a value between 1 and 10 for rows: ";
	cin >> rowInputB; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInputB; 
	}
	while( rowInputB > 10 || rowInputB <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> rowInputB;
	}
	cout << "enter a value between 1 and 10 for columns: ";
	cin >> colInputB; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInputB; 
	}
	while( colInputB > 10 || colInputB <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> colInputB;
	}
	float matrixB [rowInputB][colInputB];
	
	for (int row = 0; row < rowInputB; row++) {
		for ( int col = 0; col < colInputB; col++) {
			cout << "please enter value for (" << row + 1 << "," << col + 1 <<") :";
			cin >> matrixB[row][col];
			while(cin.fail()) {	//error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> matrixB[row][col];
			}
		}
	}
	cout << "created matrix 2 with values: " << endl;
	for (int row = 0; row < rowInputB; row++) {
		for (int col = 0; col < colInputB; col++) {
			cout << setw(4) << matrixB [row][col];
		}
		cout << endl;
	}
	cout << endl;
	

	if (rowInputA == rowInputB && colInputA == colInputB) {
		float sum [rowInputA][colInputA];
		float diff [rowInputA][colInputA];
		for (int i = 0 ; i < rowInputB; i++){
			for (int j =0; j < colInputB; j++){
				sum[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
		cout << "Sum of matrices:" << endl;  
		for (int row = 0; row < rowInputB; row++) {
			for (int col = 0; col < colInputB; col++) {
				cout << setw(4) << sum [row][col];
			}
			cout << endl;
		}
		for (int i = 0; i < rowInputB; i++){
			for (int j = 0 ; j < colInputB; j++){
				diff[i][j] = matrixA[i][j] - matrixB[i][j];
			}
		}
		cout << "Difference of matrices:" << endl;
		for (int row = 0; row < rowInputB; row++) {
		for (int col = 0; col < colInputB; col++) {
			cout << setw(4) << diff [row][col];
		}
		cout << endl;
	}
	}
	else {
		cout << "matrices are not the same size. Skipping addition and subtraction." << endl;
	}
	
	if( colInputA == rowInputB) {
		float product [rowInputA][colInputB];
		for (int i = 0; i < rowInputA; i++) {
			for (int j = 0; j < colInputB; j++) {
				for(int k = 0; k < colInputA; k++) {
					product[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		cout << "The final product of the mutliplication is: " << endl;
		for (int row = 0; row < rowInputB; row++) {
			for (int col = 0; col < colInputB; col++) {
				cout << setw(4) << product [row][col];
			}
			cout << endl;
		}
	}
	else{ 
		cout  << "The Dimensions do not match. Multiplication not possible" << endl;
	}
			
return 0;
}
