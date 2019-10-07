#include <cmath>
#include <iostream>
#include <cstring>
using namespace std; 

int main() {
	bool prime[101];
	//this sets everything in prime to true
	memset(prime, true, sizeof(prime));
	//set 1 to false manually, given the definition of prime numbers
    prime[0] = false;
	prime[1] = false;
	//starting from 2, if the number is a multiple of the outer loop number, the inner loop sets all factors of that number to false because they are not prime
	for (int i =2; i <= sqrt(100); i++){
		for (int j = i*2; j <sizeof(prime); j = j+i){
			prime[j] = false;
		}
	}
	int counter = 0;
	
	for (int i = 0; i < 101; i++){
		if (prime[i] == true){
			cout << i << " is a prime number." << endl;
			counter++;
		}
	}
	cout << "there are " << counter << " prime numbers between 0 and 100" << endl;
	return 0;
}
 
