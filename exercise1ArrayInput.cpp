#include <iostream>
#include <string>
using namespace std;

class userInput {
	private: 
		int input;

	public:
		userInput() {
			cout << "Please enter an interger: ";
			cin >> input; 
			while(cin.fail()) { //error handling loop
				cout << "Error: Not a number" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> input; 
			}
		}
		
		int getInput(){
			return input; 
		}
};

int main(){
	int a[5];
	int *ptr;
	for(int i = 0; i  < 5; i++){
		ptr = &a[i];
		userInput obj = userInput();
		*ptr = obj.getInput();
	}
	cout << "entered integers with the values: " << endl;
	ptr = &a[0];
	for(int i = 0; i < 5; i++){
		cout << *ptr + i << " is saved at " << &ptr + i << endl;
	}
    return 0;
}
