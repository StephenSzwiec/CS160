#include <iostream>
using namespace std;

void printArray(int array[], int length){
	for ( int i = 0; i < length; i++) {
		//cout << array[i] << " ";
		cout << &array[i] << endl;
	}
	cout << endl;
}

void swap_values(int* p, int* q){
	int temp = *p;
	*p = *q; 
	*q = temp;
}

void bubbleSort(int array[], int length){
	bool isSwapped = true; 
	for(int i=1;i<length;++i){
		cout << &array[i] << endl;
		for(int j=0;j<(length-i-1 );++j){ 
			isSwapped = true;
			if(array[j]>array[j+1])
			{
				swap_values(&array[j], &array[j+1]);
				isSwapped = false;
			}
		}
		if (isSwapped == true){
			break;
		}
	}
}

int main(){
	int a[] = {88, 53, 46, 23, 112, 45, 68, 29, 222};
	int size = sizeof(a)/sizeof(a[0]); //find true length of a
	for ( int i = 0; i < size; i++){
		cout << "main array" << &a[i] << endl;
	}
	cout << endl;
	printArray(a, size);
	bubbleSort(a, size);
	//after sorting
	printArray(a, size);
	return 0;
}

