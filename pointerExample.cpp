#include <iostream>
using namespace std;
int main() {
	int a; //variable
	int* ptr1; //pointer
	int** ptr2; //pointer to a pointer
	a = 5; 
	cout << a << endl; //prints out what's in side a
	cout << &a << endl; //prints out the memrory address of a
	
	ptr1 = &a; // put the memory address of a into the pointer
	cout << ptr1 << endl; //prints out vales inside ptr1
	cout << &ptr1 << endl; //shows the memory address of ptr1;  
	cout << *ptr1 << endl; 
	
	int b = 10;
	ptr1 = &b; 
	cout << *ptr1 << endl; //prints out what is in the memory address called by ptr1 (aka b = 10)
	ptr1 = *ptr2; //pointer2 points to first pointer's memory address, becoming a copy of it at this state of the code
	cout << &ptr2 << endl; //declares ptr2 as pointer of ptr1 
	cout << ptr2 << endl; //prints memory address of pointer1
	cout << *ptr2 << endl;
	cout << **ptr2 << endl; //prints what pointer2 is pointing to aka 
	return 0;
}
