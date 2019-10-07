#include <iostream>
#include <cmath>
#include <iomanip> //manipulates input/output, used for setw() function to make this pretty
using namespace std;

// this program prints out an array called 'b' as rows and columns 
int main() {  
	int rowInput, colInput;
	cout << "enter a value between 1 and 10 for rows: ";
	cin >> rowInput; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInput; 
	}
	while( rowInput > 10 || rowInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> rowInput;
	}
	cout << "enter a value between 1 and 10 for columns: ";
	cin >> colInput; 
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInput; 
	}
	while( colInput > 10 || colInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> colInput;
	}
	int b [rowInput][colInput];
	
	for (int row = 0; row < rowInput; row++) {
		for ( int col = 0; col < colInput; col++) {
			cout << "please enter value for (" << row + 1 << "," << col + 1 <<") :";
			cin >> b[row][col];
			while(cin.fail()) {	//error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> b[row][col];
			}
		}
	}
	
	for (int row = 0; row < rowInput; row++) {
		for (int col = 0; col < colInput; col++) {
			cout << setw(4) << b[row][col];
		}
		cout << endl;
	}
	cout << endl;
	
	//include a variable for column and total sums and averages 
	int colSum, rowSum, totalSum = 0;
	float colAvg, rowAvg = 0.0;
	
	//column-wise sums and averages and adding to sums
	for (int col = 0; col < colInput; col++) {
		for (int row = 0; row < rowInput; row++) {
			colSum = colSum + b [row][col];
		}
		totalSum = totalSum + colSum; 
		cout << "The sum of column " << col + 1 << " is: " << colSum << endl;
		colAvg = float(colSum)/rowInput; 
		cout << "The average of column " << col + 1 <<" is: " << colAvg << endl;
		//reset these to zero for the next loop
		colSum = 0;
		colAvg = 0;
	}
	
	//row-wise sums and averages
	for (int row = 0; row < rowInput; row++){
		for (int col = 0; col < colInput; col++){
			rowSum = rowSum + b[row][col];
		}
		cout << "The sum of row " << row  + 1 << " is: " << rowSum << endl;
		rowAvg = float(rowSum)/colInput;
		cout << "The average of row " << row + 1 << " is :" << rowAvg << endl;
		//reset to zero for next loop
		rowSum = 0;
		rowAvg = 0;
	}
	
	//totals
	cout << "The sum of all elements is: " << totalSum << endl;
	float totalAvg = totalSum / (rowInput * colInput); 
	cout << "The average of all elements is: " << totalAvg << endl;
return 0;
}

