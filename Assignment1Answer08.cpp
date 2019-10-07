#include <iostream>
#include <string>
using namespace std;

//written by Stephen Szwiec 
int main() {
	cout << "This program prints the size of C++ data types in bytes." << endl;
	cout << "The size of data type 'bool' is: " << sizeof(bool) << endl; //only 1bit, but sizeof() only returns full bytes
	cout << "The size of data type 'char' is: " << sizeof(char) << endl;
	cout << "The size of data type 'wchar_t' is: " << sizeof(wchar_t) << endl;
	cout << "The size of data type 'short' is: " << sizeof(short) << endl;
	cout << "The size of data type 'int' is: " << sizeof(int) << endl;
	cout << "The size of data type 'long' is: " << sizeof(long) << endl;
	cout << "The size of data type 'long long' is: " << sizeof(long long) << endl;
	cout << "The size of data type 'float' is: " << sizeof(float) << endl;
	cout << "The size of data type 'double' is: " << sizeof(double) << endl;
	cout << "The size of data type 'long double' is: " << sizeof(long double) << endl;
	cout << "Thanks and have a great day." << endl;
	return 0; //exit system code is read by the kernel
}

/* program output from machine using GCC x86_64 7.3.0: 
 * The size of data type 'bool' is: 1
 * The size of data type 'char' is: 1
 * The size of data type 'wchar_t' is: 4
 * The size of data type 'short' is: 2
 * The size of data type 'int' is: 4
 * The size of data type 'long' is: 8
 * The size of data type 'long long' is: 8
 * The size of data type 'float' is: 4
 * The size of data type 'double' is: 8
 * The size of data type 'long double' is: 16
*/
