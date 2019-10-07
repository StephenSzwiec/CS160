#include <iostream>
#include <iomanip> //setw() 
#include <string.h> //memset()
using namespace std;

int main (){
	bool m[9][6];
	memset(m, true, sizeof(m));
	
	for (int y = 0; y < 6; y++){
		for(int x = 0; x<9; x++){
			cout << setw(2) << m[x][y];
		}
		cout << endl;
	}
	
	cout << "Press any key to continue...";
	cin.get();
	
	m[2][4] = false;
	
	for (int y = 0; y < 6; y++){
		for(int x = 0; x<9; x++){
			cout << setw(2) << m[x][y];
		}
		cout << endl;
	}
	
	return 0;
}


	
