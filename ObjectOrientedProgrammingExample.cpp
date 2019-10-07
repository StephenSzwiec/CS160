#include <iostream>
using namespace std;


class leftHand{
	public: 
		void pick(){
			cout << "Left hand pick initiated: " << endl;
		}
		void wave(){
			cout << "I am waving my left hand" << endl;
		};
}; // classes end in semicolon

class rightHand{
	public: 
		void pick(){
			cout << "Right hand pick initiated: " << endl;
		}
				void wave(){
			cout << "I am waving my right hand" << endl;
		};
}; 

class Print{
	private:
		string name;
	public:
		void setName(string x){
			name = x;
		}
		void getName(){
			cout << name;
		};
};

int main(){
	 //create new object of leftHand class and save it as obj1
	leftHand obj1; 
	//call pick for obj 
	obj1.pick();
	rightHand obj2;
	obj2.pick();
	return 0;
}
