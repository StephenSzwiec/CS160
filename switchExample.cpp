#include <iostream>
using namespace std;

int main() {
//	const int spades = 0;
//	const int hearts = 1;
//	const int diamonds = 2;
//	const int clubs = 3; 
//	int suit; 

	const int ace = 1; 
	const int jack = 11;
	const int queen = 12;
	const int king = 13; 
	int rank = 15;
	while (rank == 15) {
		cout << "please enter rank (1-13)" << endl;
		int input;
		cin >> input;
		if ( input >= 1 && input <= 13){ 
			rank = input;
		}
		else {
			cout << "input invalid, please try again" << endl;
		}
	}
	switch (rank)
	{	
		case ace: 
			cout << "the card is an Ace." << endl;
			break;
		case jack:
			cout << "the card is a Jack." << endl;
			break;
		case queen: 
			cout << "the card is a Queen." << endl;
			break;
		case king:
			cout << "the card is a King." << endl;
			break;
		default:
			cout << "the card is a " << rank << "."<< endl;
			break;
	}
	return 0; //exit system code is read by the kernel
}
