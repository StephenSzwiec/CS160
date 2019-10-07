// logic of elements is (Rows + 1)^2 + Rows
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
	for (int i=0; i < rows; i++){
        for(int j = 0; j < rows -i -1; j++){
                // this loop builds the spaces ahead of the elements
                cout << " ";  	
        }
        for(int	k = 0; k <= i; k++){
	        cout <<	(i + 1) * (i + 1) + i << " ";
        }
        cout <<	endl;
	}	
return 0;
}




