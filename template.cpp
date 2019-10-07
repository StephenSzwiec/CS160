#include <iostream>
using namespace std;

int main() {
	int x;
	int i = -2;
	x = -4 * i++ - 4 % 4; 
	cout << x; 
	return 0; //exit system code is read by the kernel
}
