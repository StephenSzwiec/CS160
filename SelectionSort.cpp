#include <iostream>
using namespace std;
int main(){
	int min, index;
	int a[] = {1,5,4,3,2};
	int temp;
	int size = sizeof(a)/sizeof(a[0]); //find true length of a

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for ( int i = 0; i < size - 1; i++) {
		min = a[i];
		index = i;
		for ( int j = i; j < size; j++) {
			if ( a[j] < min ) {
				min = a[j];
				index = j;
			}
		}
		temp = a[i];
		a[i] = min;
		a[index] = temp;
	}

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
