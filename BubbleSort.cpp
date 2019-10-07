#include <iostream>
using namespace std;

int main () {
	int a[] = {88, 53, 46, 23, 112, 45, 68, 29, 222};
	int temp = 0;
	int size = sizeof(a)/sizeof(a[0]);//find true length of a
	int counter = 0;
	
	//before sorting
	for ( int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for(int i=1;i<size;++i){
		for(int j=0;j<(size -1 );++j){
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				counter++; 
			}
		}
	}
	
	//after sorting
	for ( int i = 0; i < size; i++) { 
		cout << a[i] << " ";
	} 
	cout << endl;
	cout << counter << endl;
	return 0;
}
