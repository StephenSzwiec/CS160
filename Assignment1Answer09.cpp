#include <iostream>
#define _USE_MATH_DEFINES //allows for defined constants from math.h 
#include <math.h> // import math header for pi constant use
using namespace std;

float circum(float rad);
float cirarea(float rad);

int main() {
	cout << "This program computes and prints the circumference \n and area of a circle with radius of 2.5cm." << endl;
	float radius = 2.5F;
	cout << "This machine's compiler defines Pi as:" << M_PI << endl; 
	cout << "This machine's compiler defines Pi as:" << M_PI_4 << endl;
	cout << "The circumference of a circle with a radius of 2.5cm is:" << endl;
	cout << circum(radius) << "cm" << endl;
	cout << "The area of a circle with a radius of 2.5cm is:" << endl;
	cout << cirarea(radius) << "square cm" << endl;
	return 0; //exit system code is read by the kernel
}

float circum(float rad) {
	return M_PI * rad * 2.0F;
}
float cirarea(float rad) {
	return M_PI * pow(rad,2.0F);
}
