#include <iostream>
#include <iomanip>
#include <chrono> 
#include <algorithm>
#include <cstdlib>    
#include <cmath>
using namespace std;
using namespace std::chrono;

class timer{
	private:
		high_resolution_clock::time_point start; 
		high_resolution_clock::time_point stop;
	public:
		void startTimer(){
			start = high_resolution_clock::now(); 
		}		
		void stopTimer(){
			stop = high_resolution_clock::now(); 
		}
		auto getDuration(){
			auto duration = duration_cast<microseconds>(stop - start); 
			return duration.count();
		}
};

class userInput {
	private: 
		char input; 
	public:
		
		userInput() {
			cout << "Please enter an integer: ";
			cin >> input; 
			while(cin.fail()) { //error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> input; 
			}
			while (input != '1' && input != '2' && input != '3' && input != '4') { //error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> input;
			}
		}
		
		char getInput(){
			return input; 
		}
		
		
};

class boolInput{
	private:
		char input; 
		bool isSelected;
	
	public:
		boolInput(){
			cout << "Y/N? ";
			cin >> input; 
			while(cin.fail()) { //error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> input; 
			}
			while (input != 'Y' && input != 'N' && input != 'n' && input != 'y') { //error handling loop
				cout << "Please enter (y)es or (n)o" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> input;
			}
		}
		
		bool getSelection(){
			if (input == 'Y' || input == 'y'){
				isSelected = true;
			}
			else{
				isSelected = false;
			}
			return isSelected;
		}
};

void swap_values(int* p, int* q){
	int temp = *p;
	*p = *q; 
	*q = temp;
}

void printArray(int array[], int length){
	for ( int i = 0; i < length; i++) {
		cout << setw(5) << array[i];
	}
}

void bubbleSort(int array[], int length){
	for(int i=1;i<length;++i){
		for(int j=0;j<(length -1 );++j){
			if(array[j]>array[j+1])
			{
				swap_values(&array[j], &array[j+1]);
			}
		}
	}
}

void optimizedBubbleSort(int array[], int length){
	bool isSwapped = true; 
	for(int i=1; i<length ;++i){
		isSwapped = true;
		for(int j=0; j< length -i ;++j){ 
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

void selectionSort(int array[], int length){
	int min, index, temp;
	for ( int i = 0; i < length - 1; i++) {
		min = array[i];
		index = i;
		for ( int j = i; j < length; j++) {
			if ( array[j] < min ) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = min;
		array[index] = temp;
	}
}

void merge(int array[], int left, int middle, int right){
	//create global variables used
	int i, j, k; //indexes
	int lengthLeft = middle - left + 1; //size of temp array left 
	int lengthRight = right - middle; //size of temp array right
	
	//create temp arrays
	int leftArray[lengthLeft], rightArray[lengthRight];
	
	//copy data to temp arrays 
	for (i = 0; i < lengthLeft; i++){
		leftArray[i] = array[left+i];
	}
	for (j = 0; j < lengthRight; j++){
		rightArray[j] = array[middle + 1 + j];
	}

	//reset indexes
	i = 0; //initial index of left subarray
	j = 0; //initial index of right subarray
	k = left; //initial index of merged subarray
	
	while ( i < lengthLeft && j < lengthRight){
		if (leftArray[i] <= rightArray[j]){
			array[k] = leftArray[i];
			i++;
		}
		else{
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}
	
	//copy any remaining elements of left array 
	while (i < lengthLeft){
		array[k] = leftArray[i];
		i++;
		k++;
	}

	//copy any remaining elements of right array
	while(j < lengthRight){
		array[k] = rightArray[j];
		j++;
		k++;
	}
	
}

void mergeSort(int array[], int left, int right){
	if (left < right){
		int middle = left + (right - left) / 2;
		//sort first and second halves
		mergeSort(array, left, middle);
		mergeSort(array,middle+1, right); 

		merge(array, left, middle, right);
	}
}

int main(){
	cout << "This program performs time analysis on sorting algorithms." << endl;
	cout << "Do you want array output? (this can get rediculously large but helps for debugging) : " << endl;
	boolInput p = boolInput();
	cout << "Please select size of array to sort: " << endl;
	cout << setw(4) << "[1] - array of size 10" << endl;
	cout << setw(4) << "[2] - array of size 100" << endl;
	cout << setw(4) << "[3] - array of size 1,000" << endl;
	cout << setw(4) << "[4] - array of size 10,000" << endl;
	cout << "Your selection? [1-4] : ";
	userInput q = userInput(); //error handling loops are done inside the constructor
	int x = (int)pow(10,((int)q.getInput()-48)); //takes 10 to the power of the ASCII character minus 48
	timer t = timer();
	std::srand ( unsigned ( std::time(0) ) ); //set the random seed for this program
	int a[x];
	int c[x];

	for (int i = 0; i < x; i++){
		a[i] = i+1;
	}
	random_shuffle(&a[0], &a[x]);
	for (int i = 0; i < x; i++){
		c[i] = a[i];
	}
	if(p.getSelection() == true){
		cout << "created array with " << x << " elements and the following shuffled values: " << endl;
		printArray(c,x);
	}
	cout << endl;
 
	t.startTimer();
	bubbleSort(c,x);
	t.stopTimer();
	cout << endl;
	cout << "bubble sorted array in " << t.getDuration() << " microseconds ";
	if(p.getSelection() == true){
		cout << "with results: " << endl;
		printArray(c,x);
	}
	cout << endl;

	for (int i = 0; i < x; i++){
		c[i] = a[i];
	}

	t.startTimer();
	optimizedBubbleSort(c,x);
	t.stopTimer();
	cout << endl;
	cout << "optimized bubble sorted array in " << t.getDuration() << " microseconds ";
	if(p.getSelection() == true){
		cout << "with results: " << endl;
		printArray(c,x);
	}
	cout << endl;
	
	for (int i = 0; i < x; i++){
		c[i] = a[i];
	}
	
	t.startTimer();
	selectionSort(c,x);
	t.stopTimer();
	cout << endl;
	cout << "selection sorted array in " << t.getDuration() << " microseconds ";
	if(p.getSelection() == true){
		cout << "with results: " << endl;
		printArray(c,x);
	}
	cout << endl;
	
	for (int i = 0; i < x; i++){
		c[i] = a[i];
	}
	
	t.startTimer();
	mergeSort(c,0,x-1);
	t.stopTimer();
	cout << endl;
	cout << "merge sorted array in " << t.getDuration() << " microseconds";
	if(p.getSelection() == true){
		cout << "with results: " << endl;
		printArray(c,x);
	}
	cout << endl;
	
	return 0;
}
