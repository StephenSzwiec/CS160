#include <iostream>
using namespace std;

void newswap(int * p, int * q){
	int temp; 
	temp = *p;
	*p = *q;
	*q = temp;  
	cout << "test" << endl;
}

int main(){
	int c = 5;
	int d = 10;
	newswap (&c, &d);
	cout << "c is set to: " << c << endl; 
	cout << "d is set to: " << d << endl;
	return 0;
}
