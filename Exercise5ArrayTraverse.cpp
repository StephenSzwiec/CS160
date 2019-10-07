#include <iostream>
using namespace std;
int main(){
	int array[] = {1,2,3,4,5,6};
	int* p = &array[0];
	for(int i = 0; i < 6; i++){
		cout << *p + i << endl; 
	}
	return 0;
}
