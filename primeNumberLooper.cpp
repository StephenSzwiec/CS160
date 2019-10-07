#include <cmath>
#include <iostream>
using namespace std; 

int main() {
	//set 1 to be not prime, given the definitiion of a prime
	int counter = 0; 
	
	for (int number = 2; number < 100; number++){
		bool prime = true;
		
		for (int factor = 2; factor <= sqrt(number); factor++) {
			if ((number > factor) && (number % factor == 0)) { 
				prime = false;
			}
		}
		if (prime == true){
			cout << number << " is prime" << endl;
			counter++; 
		}
	}
	
	cout << "there are " << counter << " prime numbers between 1 and 100." << endl;
	 
	return 0;
}

