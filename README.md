# CS160
Dumping ground for old C++ class projects 

The following class was presented by Mr Rahul Gomes of Minot State University Spring Semester 2019. The following notes were compiled from his lectures and teaching during this time and represent a crash course into C++ basics

-> Suggested book: "A First Book of C++" - Gary Bronson
-> Suggested IDE: Dev++ for compiling and writing programs

==C++ Basics============================================================

A. What is C++ ? - an overview:
	1. Extension of C...
		-> universal
		-> efficient
		-> close to the machine
		-> portable
	2. ...that allows for Object Oriented Programming...
		-> data abstraction
		-> data hiding
		-> polymorphism/inheritance
	3. ... and Extensions
		-> extension handling
		-> templates
B. C++ was created by Bjarne Stroustrup and others at Bell Labs
	1. "C with Classes" published in 1980
	2. ANSI C++ - published as an industry standard
	3. Comparing C++ vs Traditional procedural programming
		-> All data must be initialized before use
		-> If a record is extended, corresponding functions must also be modified
		-> Errors are hard to track
		-> High program maintenance for legacy code
	4. Instead, concept of Functional Programming to increase code reuse/refactoring in the future
	5. Functional Programming allows for higher code integreation when making large applications as teams
C. Flowchart of how C++ code becomes an Executable
________________________________________________________________________
____________
|           |
| source    |
| file      |  <-- the source file is typed in an IDE or other text editor by the programmer
|___________|
     |                ___________
     |                |          |
 compiler <-----------|  header  | <-- included C++ libraries
     |                |  file    |
     |                |__________|
     V
____________
|           |
| object    |
| file      |  <-- machine readable object
|___________|
     |
     |                _____________
   linker <-----------|            |
     |    ^           |  standard  |
     |    |           |  library   |
     |    |           |____________|
     |    |______________________________
     |                |                  |
     V                |  obj files       |
_____________         |  other libraries |
|            |        |__________________|
| executable |
|____________|
________________________________________________________________________

D. Exit Status
	1. the program is started by the user, but the kernel assigns memory to it until it gives a return code
	2. Exit Status of 0 is used to tell the kernel the program processed without problems, while non-zero exit codes are used for errors

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
//hello world program example
int main() {
	cout << "Enjoy yourself with C++!" << endl;
	return 0; // this return statement is where we tell the kernel we are finished
}
////////////////////////////////////////////////////////////////////////
E. What is an Identifier
	1. labels, types, variables
	2. can't be a system reserved word
	3. must be unique
	4. must start with a letter or _underscore_ and be followed by numbers, letters, or underscores
F. C++ Data Types
	1. Simple Data Types
		  i. Integral - Primitive
			-> char (ASCII)
			-> short
			-> int
			-> long
			-> bool
		 ii. Enum
		iii. Floating
			-> float
			-> double
			-> long
	2. Complex Data Types
		  i. Pointer
		 ii. Reference
	3. Structured
		  i. Array
		 ii. Struct
		iii. Union
		 iv. Class
// geeksforgeeks.org/c-data-types/ <- this describes the data sizes in C
G. Pointers
	1. Pointers are used to access variables in an array
	2. * is used to denote pointers such that
	//int * p = new int;
	3. this creates a default constructed int on free store and asssigns a pointer to it
H. Expressions can be used to
	1. declare a variable or constant
	2. do an operation (a+b; a*2)
	3. call a function
	4. variables go on the left, functions go on the right
=======================================================End of C++ Basics


==Binary Math===========================================================

A. Background
	1. Computers work by reading only two types of information:	 i. Instructions
		ii. Data
	2. Machine language constitute hundreds of instructions given to the CPU
	3. A program is a list of instructions executed by the CPU
	4. Computers internally only recognize on or off; this information constitutes bits
	5. This system is Binary or Base 2
B. Converting Binary to Decimal
	//take each place of the number starting with the right hand side as 2^0 and then add each number as a representation of 2^n, for example:
	1   0   0   1   0   0   1   1
	2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
	128 0   0   16  0   0   2   1   = 147
C. Bytes
	1. Eight bits form a single byte
	2. Byte Values: 0 - 255
	3. As a result, binary numbers almost always written as full byte (00000001)
D. Binary to Hexadecimal
	1. Base 16 sometimes used as output to save space or to map logical bits into a more human readable format
	2. 16 characters 0-F are used
	3. Every Hex character represents 4 bits
	4. 2 nibbles (2 hex chars) = 1 byte
	5. Easier to write large numbers faster
	6. Conversion between hex and bin is just taking hex conversion of each 4 binary numbers
E. ASCII
	1. provides a code table, which is used to represent bytes as symbols
		-> 0100 0001 (41 hex) = A
		-> 0100 0010 (42 hex) = B
F. Binary Addition/Subtraction
	1. binary numbers can be added by adding each and carrying across; however, memory may only store so many bits of information
	2. most varibles are "signed"
		-> one less bit for information
		-> the first bit is instead used to provide positive or negative sign
	3. to subtract signed numbers, simple addition of a negative does not provide the correct answer because of overflow into the signed bit
	4. to get around this, 1's complement is sometimes used instead, in which the negative number has all bits except the sign flipped
	//ex 7 - 3, or 0111 + 1100 becomes 0111 + 1100 instead, which gives the correct answer: 0100 = 4
	5. the problem with early computing and 1's complement was that 0 had two values (0000 and 1111), and the carry bit is lost
	6. modern computer science uses 2's complement, which is 1's complement taken with 1 added to the answer
	//ex 7 - 3, or 0111 - 1100 becomes 0111 + 1101 = 0100 = 4
======================================================End of Binary Math


==Functional Programming================================================

A. Functions
	1. member functions are how the instructions are organized by the machine, and how code is organized as well
	2. Global function - main()
		-> starting point for all other functions
	3. Functions either return type void or a data type (int, float)
	4. Function Prototyping
		-> by default functions must be declared before the main function
		-> prototyping declares the function before writing the code
		-> gives you the freedom to write functions after the main function in the code

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
void line(), message(); //prototypes
int main() {
	cout << "Hello! This program starts in main()." << endl;
	line();
	message();
	cout << "At the end of main()." << endl;
return 0;
}
void line() {
	cout << "------------------------" << endl;
}
void message() {
	cout << "In function message()." << endl;
}
////////////////////////////////////////////////////////////////////////

B. Type Conversions
	1. Datatypes can be converted via explicit calls to their types
	2. Mixing int and float type variables for math will give unexpected results

//example///////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
int main(){
	int a = 5;
	int b=2;
	int c = a/b;
	cout <<c<<endl;

	float d = a/b;
	cout <<d<<endl;
	float e = float(a/b);
	cout <<e<<endl;

	float f = float(a)/b;
	cout <<f<<endl;

	float g = 5;
	int h=2;
	float i = g/h;
	cout <<i<<endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////
===========================================End of Functional Programming


Basic Control Structures================================================

A. Algorithms
	1. in computing, tasks and problems can be solved by executing a series of actions in order
	2. algorithm is a procedure determining actions and order of execution
	3. specifying what statements in a program should be executed can be done by the program via algorithms
B. Pseudocode
	1. similar to everyday english, break the problem down into steps taken to solve it
	2. not executed on computers, rather a planning step taken to produce the answer before code is written
C. Control Structures
	1. executed in sequence
	2. transfer control to the next statement
	3. 3 control structures:
		-> if/else
		-> switch
		-> loops (while, do/while, for)
D. Flowcharting
	1. Graphical representation of a program
	2. Special purpose symbols connected by arrows
	3. Allow for a better understanding of the control structure of a program before code is written

// if-else example /////////////////////////////////////////////////////
#include <iostream>
using namespace std;
int main(){
	float x, y, min;
	cout << "Enter two different numbers:\n";
	if( cin >> x && cin >> y)
	{
		if( x < y ){
			min = x;
		}
		else
			min = y;
		cout <<"\nThe smaller number is: " << min << endl;
	}
	else
	cout <<"\nInvalid Input!" << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////

E. Expression combinations
	1. the &&, ||, and ! operators allow one to combine expressions
//example///////////////////////////////////////////////////////////////
if ( age >= 13 && age < 17){
	cout << "You can go to G and PG-13 rated movies" << endl;
}
////////////////////////////////////////////////////////////////////////
	2. boolean operators behave such that
		-> && - true if all conditions are true
		-> || - true if one condition is true
		-> !  - true if conditions are false
F. If/else structures can be nested to provide conditions for more complicated situations

G. Switches
	1. allow for control structures with multiple finite discrete states instead of just boolean true/false statements
	2. should be given a default case so the program does not hang
	3. break; is used after each case to exit the switch

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main() {
//	const int spades = 0;
//	const int hearts = 1;
//	const int diamonds = 2;
//	const int clubs = 3;
//	int suit;

	const int ace = 1;
	const int jack = 11;
	const int queen = 12;
	const int king = 13;
	int rank = 15;
	while (rank == 15) {
		cout << "please enter rank (1-13)" << endl;
		int input;
		cin >> input;
		if ( input >= 1 && input <= 13){
			rank = input;
		}
		else {
			cout << "input invalid, please try again" << endl;
		}
	}
	switch (rank)
	{
		case ace:
			cout << "the card is an Ace." << endl;
			break;
		case jack:
			cout << "the card is a Jack." << endl;
			break;
		case queen:
			cout << "the card is a Queen." << endl;
			break;
		case king:
			cout << "the card is a King." << endl;
			break;
		default:
			cout << "the card is a " << rank << "."<< endl;
			break;
	}
	return 0; //exit system code is read by the kernel

////////////////////////////////////////////////////////////////////////
=========================================End of Basic Control Structures


==Loops=================================================================
A. Overview
	1. Loops are iterative statements
	2. We often need to do repetitive calculations to solve complex problems
	//example: calculate trajectory of a cannon ball; humans are typically very bad at this but computers are very good at this
	3. C++ has three types of loops: while, for, and do-while
B. while Loops
	1. A while loop iteratively executes a block of code
	2. we need to specify the following:
		-> the initialization code to execute before the loop
		-> the logical expression for continuing
		-> the block of code to be repeated inside the loop
	3. The program will execute inside of the while loop so long as the condition remains true
	4. The code directly after the while loop is executed when it becomes false
//example///////////////////////////////////////////////////////////////
while (logical expression)
{
//block of statements to repeat
}
////////////////////////////////////////////////////////////////////////
C. Counting Loops
	1. Often it is needed to perform an operation a fixed number of times
	2. We can use a counting loop to do this operation
	3. We need to do the following:
		-> make a variable loop counter
		-> while the counter has NOT (!=) desired value it performs operations
		-> inside the loop, it increments the loop counter up or down toward the counter value
//example///////////////////////////////////////////////////////////////
int count = 0;
while (count < 10)
{
	cout << count << "squared= " << count*count << endl;
	count = count + 1;
}
////////////////////////////////////////////////////////////////////////
D. Conditional Loops
	1. Often it is needed to perform an iteration based on a data value
	2. Conditional loops allow us to process data until a given situation arises
	3. We need to do the following:
		-> perform initialization of code
		-> while the conditition is TRUE perform desired operations, then check terminating condition again
//example///////////////////////////////////////////////////////////////
int amt = 42;
while (amt > 0)
{
	cout << amt << "halved= " << amt/2 << endl;
	amt = amt/2;
}
////////////////////////////////////////////////////////////////////////
E. Infinite Loops
	1. It is possible to create while loops which execute forever
	2. These infinite loops are often unplanned and unwanted
	3. To get out of an infinite loop you need to kill the program with Ctrl+C
	4. Occasionally infinite loops are used on purpose
		-> drawing a screen for graphics
//example///////////////////////////////////////////////////////////////
while (true)
{
	cout << "Hello Mom\n"; // outputs "Hello Mom" until killed
}
////////////////////////////////////////////////////////////////////////
G. for Loops
	1. The C++ for Loop provides a compact syntax for iteration
	2. for Loops are typically used for counting loops, but they can be used for any looping
	3. Allows you to specify the following all on one line
		-> initialization statement
		-> logical expression for continuing
		-> statement to be executed next
//example///////////////////////////////////////////////////////////////
for (int num = 0; num < 10; num = num+1 )
{
	cout << num << "cubed= " << num*num*num << endl;
}
////////////////////////////////////////////////////////////////////////
	4. if the logical expression is true, the code block excutes, otherwise it is skipped
	5. infinite loops are also possible but harder to create by accident
//example///////////////////////////////////////////////////////////////
for ( ; true ; ) //semicolons are still needed even if no iterator is initialized
{
	cout << "Hi Pop\n";
}
////////////////////////////////////////////////////////////////////////
H. Converting Loops
	1. Computationally, for and while are identical; only different in syntax
	2. It is trivial to convert a while loop into a for loop
		-> change "while" to "for"
		-> keep logical expression the same
		-> keep block of statement inside loop the same
		-> leave the for loop initialization statement blank
		-> leave the for loop increment statement blank
	3. It is relatively easy to convert a for loop into a while loop
		-> change "for" to "while"
		-> move the initialization statement before while loop
		-> keep logical expression the same
		-> move block of statement into while loop body
		-> move increment to bottom of while loop body
I. Auto increment and decrement
	1. auto increment operator "++" can be used to quickly add one to integer variable
		-> instead of i = i + 1, i++
		-> similarly, j = j - j, j--
	2. there is a subtle difference between ++i and i++
		-> ++i adds to the variable before using it
		-> i++ adds to the variable after using it
	3. other shortcuts exist
		-> a = a + b, a += b
		-> c = c - d, c -= d
		-> *=, /=, and %= are also supported
		-> results in shorter and sometimes faster code
J. do while Loops
	1. C++ has another iterative statement called do while loop
	2. Unlike other loops, only checks the logical expression after the body of loop
	3. always execustes at least once
	4. if logical expression true, loop excutes again
	5. useful for a limited number of applications
//example///////////////////////////////////////////////////////////////
do
{
	cout << "Enter number between [0..9] ";
	cin >> value;
}
while ((Value < 0 || (Value > 9)); //keeps the user entering numbers until correct entry
////////////////////////////////////////////////////////////////////////
K. Nested Loops
	1. It is often nessessary for one loop to include another loop to solve a problem
	2. The nested loops need separate initializations, logical expressions, and increments
	3. Inner loops execute their own M number of times per outer loop, which is itself run N times, yielding N*M inner loops executed
//example///////////////////////////////////////////////////////////////
for (int number = 1; number <= 15; number++)
{
   // Outer loop executes 15 times
   int factorial = 1;
   for (int count = 1; count <= number; count++)
   {
      // Inner loop executes number times
      factorial *= count;
   }
   cout << " Number = " << number
           << " Factorial = " << factorial << endl;
////////////////////////////////////////////////////////////////////////

L. Software Engineering Tips
	1. Print debugging messages inside each loop with cout
	2. Make sure loop executes correct number of times: off by one errors are common
	3. Anticipate loops that may execute zero times
	4. Anticipate and avoid infinite loops; terminating condition should always get closer with each loop iteration
	5. Common mistakes to avoid:
		-> never update for loop counter variable inside for loop
		-> never use the same counter for nested loops
		-> missing or unmatched () in logical expressions
		-> missing or unmatched {} in iterative statements
		-> never use & instead of &&; | instead of ||; = instead of == in logical expressions
		-> never use ; directly after for() or while() loops

============================================================End of Loops


==Simple Calculator=====================================================
//the following program was written in course of the lecture

#include <iostream>
using namespace std

void addition (float P, float Q), subtraction (float P, float Q), product (float P, float Q), division (float P, float Q);

int main() {
    float a;
    float b;
    char opt;
    cout << "Enter 1 for add, 2 for subtract, 3 for multiply, 4 for divide" << endl;
    cin >> opt;
    cout << "Enter the first number" << endl;
    cin >> a;
    cout << "Enter the second number"  << endl;
    cin >> b;

    switch(opt){
        case '1' :
           cout << "you selected addition" << endl;
           addition(a,b);
           break;
        case '2' :
           cout << "you selected subtraction" << endl;
           subtraction(a,b);
           break;
        case '3' :
           cout << "you selected multiplication" << endl;
           product(a,b);
           break;
        case '4' :
           cout << "you selected division" << endl;
           division(a,b);
           break;
        default :
	   cout << "wrong choice. Try again << endl;
           break;
    }
}

void addition( float P, float Q){
    float result = P + Q;
    cout << "The answer is " << result << endl;
}
void subtraction(){
    float result = P - Q;
    cout << "The answer is " << result << endl;
}
void product(){
    float result = P * Q;
    cout << "The answer is " << result << endl;
}
void division(){
    float result = P / Q;
    cout << "The answer is " << result << endl;
}

========================================================================

==Fibonacci Enumerator==================================================
#include<iostream>
using namespace std;

int main(){
	int fib1=0, fib2=1,sum,n;
	cont << "Rows:";
	cin >> n;
	cout << "Which value should it stop after ?"
	cin >> val;
	for (int i = 0; i < n; i++){
		for( int j = 0; j <= i; j++){
			cout << fib1 << " ";
			sum = fib1 + fib2;
			fib1 = fib2;
			fib2 = sum;
			if (fib1 >= val){
				return 0;
			}
		}
	}
	return 0;
}
=============================================End of Fibonacci Enumerator

==Armstrong Numbers=====================================================
int num;
cout << "Please enter an integer: "
cin >> num;
int digit_num = 0;
int temp = num;
int sum = 0;
int num_1 = input;
//counts how many digits are in a nunmber
while(temp != 0){
	digit_num++;
	temp = temp / 10;

//removes each digit, then takes it to a power of itself
for(i = 0; i < digit_num; i++){
	int temp_1  = num_1 % 10;
	sum = sum + pow(temp_1,digit_num);
	num_1 = num_1 / 10;
}
//does the check if sum of digits to the power of themselves is equal to input
if(sum == num){
	cout << "It is an armstrong number." << endl;
}
else {
	cout << "It is not an armstrong number." << endl;
}
================================================End of Armstrong Numbers


==Pyramid===============================================================
cin = int rows;
//first we build the pyramid shape using two for loops
for (int i=0; i < row; i++){
	for(int j = 0; j < rows -i -1; j++){
		// this loop builds the spaces ahead of the elements
		cout << " ";
	}
	for(int k = 0; k <= i; k++){
	        cout <<	(i + 1) * (i + 1) + i << " ";
	}

	cout << endl;
========================================================================
// Alternative logic that works

for(j = row; j > i; j-- )
	cout << " ";
for(j = 0; j < i; j++)
==========================================================End of Pyramid

==Perfect Squares=======================================================

float heronMethod(double x) {
	double guess = 1;
	do {
		guess = (guess + x/guess)/2;
		cout << guess << endl;
	} while ( fabs(guess * guess - x > 0.00000001));
	return guess;
}

int main() {
	cout << "This program uses Hero of Alexandria's method of finding square roots" << endl;
	cout << "enter your number: ";
	double input;
	cin >> input;
	double output;
	output = heronMethod(input);
	cout << "the square root of " << input << " is: " << output << endl;
	return 0; //exit system code is read by the kernel
}

//a more simple version to only find perfect squares is
int main(){
	float num;
	cout << "Enter a number" << endl;
	float << root = sqrt(num);
	cout << root << endl;
	float num1 = root^2;
	cout << num1 << endl;
	if(num1 == num){
		cout << num << " is a perfect square" << endl;
	else(
		cout << num << " is not a perfect square" << endl;
================================-=================End of Perfect Squares

==Digit Reversal========================================================
int main()
{
	int n, A = 0, R;
	cout << "Enter an integer: ";
	cin >> n;

	while( n != 0)
	{
		R = n % 10;
		A = A * 10 + R;
		n = n / 10;
	}
	cout << " A = " << A;
	return 0;
}
////////////////////////////////////////////////////////////////////////
This program takes input n and transforms it by taking the remainder R
of the number divided by 10, and adding it to a holding variable A,
then subtracting from n the proceeding digits (found as n / 10).
As such, this program loops through the digits of a decimal integer
and reverses the digits.
===================================================End of Digit Reversal

==Greatest==============================================================
using namespace std;
#include <iostream>
//calculates the greater of two input integers
void calc_greatest( int a, int b) {
	if (a > b)
	{
		cout << a < " is greatest";
	}
	else if (a == b)
	{
		cout << a << " & " << b << " are equal.";
	}
	else
	{
		cout << b << " is greatest.";
	}
}

int main()
{
	int num1, num2;
	cout << "enter first number: ";
	cin >> num1;
	cout << "enter second number: ";
	cin >> num2;
	calc_greatest(num1, num2);
	return 0;
}
=========================================================End of Greatest


=Strings================================================================

A. Literal Strings
	1. Literal strings are arrays of char (char array[])
	2. the length of literal strings must be declared before they are used
	3. the characters of literal strings have to be changed one at a time
//example///////////////////////////////////////////////////////////////
char s[] = "Hello World!"
//char s[0] is H, char s[1] is e, etc.
////////////////////////////////////////////////////////////////////////
	4. spaces in ASCII are stored as '\0' or null, which tells the program the literal string is to have no character
////////////////////////////////////////////////////////////////////////
...
int i;
char s[] = "Hello World";

cout << s << endl;

i = 0;
while ( s[i] != '\0')
{
	cout << s[i] << ","
	i++;
}
cout << endl;
cout << "s[" << i << "] = " << int(s[i]) << endl;
////////////////////////////////////////////////////////////////////////
	5. there is an extra character at the end of every literal string, which is also '\0' and signals the end of the string
	6. A literal string variable cannot be changed, ie the following is a syntax error
////////////////////////////////////////////////////////////////////////
char s[] = "Hello World";
s = "Goodbye World"; //cannot change the size or content of the entire literal string
s[1] = 'o' // this works, because you can change single characters
////////////////////////////////////////////////////////////////////////
	7. if you wanted to do simple transformations on characters, you can do this arithmetically
////////////////////////////////////////////////////////////////////////
...
char a[] = "Hello"
for ( i = 0; i < 4; i++)
	if( a[i] >= 97 && a[i] <= 122)
	{
		a[i] = char( int(a[i]) - 32 ) // converts lowercase to uppercase
	}
}
cout << a[]; // prints "HELLO"
////////////////////////////////////////////////////////////////////////

B. C-style Strings
	1. C-style string is stored in an array of char
	2. C-style strings strings should always end in '\0'
		-> null characters terminate the string whenever they are in the string
		-> a lack of null character at the end can lead to unexpected behavior
//example///////////////////////////////////////////////////////////////
//this is a literal string
char s[] = "Hello";
cout << t[] << endl;
//you start the C-style string by giving it the max length first
char a[6] = { 'H', 'e', 'l', 'l', 'o', '\0'}; // terminates as expected
char a[8] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o'} // prints out "Hello Wo)" because of wonky implementation
char a[9] = { 'H', 'e',	'l', 'l', 'o', ' ', 'W', 'o', '\0'} // correctly prints out the string "Hello Wo"
////////////////////////////////////////////////////////////////////////
	3. Problems with C-style strings
		-> forgetting to end the string with '\0'
		-> not allocating enough memory for the string
		-> you cannot easily add an element to the string
		-> you cannot easily delete an element from the string
		-> you cannot concatenate two strings
C. C++ string class
	1. C++ string class requires // #include <string>
	2. to create a variable of type string, simply: // string lastName = "Gomes"; or string lastname("Gomes");
	3. you can replace C++ strings without initializing new variable
	4. Concatenation (+): adding two strings yields a string
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

int main() {
	string firstN, lastN;
	cout << "Please enter first name: " << endl;
	cin >> firstN;
	cout << "Please enter last name: " << endl;
	cin >> lastN;
	string fullN = firstN + " " lastN;
	cout << fullN;
	return 0;
}
////////////////////////////////////////////////////////////////////////
	4. space problem with C++ strings
		-> cin does not count anything after spaces given in (because they are '\0')
		-> getline( source, destination) gets around this
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

int main() {
        string firstN, lastN;
        cout << "Please enter first name: " << endl;
        getline(cin, firstN); // this wraps the cin and captures spaces as well
        cout << "Please enter last name: " << endl;
        getline(cin, lastN);
        string fullN = firstN + " " lastN;
        cout << fullN; //allows names like "Billy Bob Joe Francis" in this case
        return 0;
}
////////////////////////////////////////////////////////////////////////
	5. String processing
		-> string s[n] still invokes the n'th element of string just like literal and C-type strings
		-> you can do relational operations with strings (==, >, <, !=, >=, <=) to compare strings or elements of strings
		-> comparing two strings searches strings "like a dictionary" such that "john" is less than "johp"

//review////////////////////////////////////////////////////////////////

Literal strings // char s[] = "Hello";

C-style strings // char s[6] = {'H','e','l','l','o','\0'};

C++ string class // string s = "Hello";

getline(source, destination) prevents spaces in standard input from breaking strings
////////////////////////////////////////////////////////////////////////

==Strings===============================================================
	6. Additional properties of class strings
		-> C++ class strings do not end in an invisible '\0'
		-> stringname.length() gives the number of characters of a string
		-> invoking stringname[n] gives the n'th letter of a string
//example///////////////////////////////////////////////////////////////

//this program prints "yes" if the first name begins with 'A' and "no" otherwise
#include <string>
#include <iostream>
using namespace std;

int main () {
	string fName;
	cout << "Enter your first name: ";
	getline(cin,fName);
	if (fName[0] == 'A' ) {
		cout << "Yes." << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////

		-> substr (index, n) creates a substring starting at index number, and takes the length n characters
//example///////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace std;

int main () {
        string fName;
        cout << "Enter your first name: "; //"JohnDoe"
        getline(cin,fName);
        cout << fName.substr(2,3); // "hnD"
	return 0;
}
////////////////////////////////////////////////////////////////////////

		-> replace(index, n, str) removes n characters in the string starting from the index, and inserts str in its place
//example///////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace std;

int main () {
        string s = "Speed Boat";
	s.replace(0, 5, "Sail");
	cout << s << endl; // prints "Sail Boat"
	return 0;
}
////////////////////////////////////////////////////////////////////////

	->insert(index, str) inserts the specified string at the specified index
//example///////////////////////////////////////////////////////////////

//this program prints "yes" if the first name begins with 'A' and "n$
#include <string>
#include <iostream>
using namespace std;

int main () {
        string animal = "Hippo";
	animal.insert(0, "Happy ");
	cout << animal << endl; //"Happy Hippo"
////////////////////////////////////////////////////////////////////////

==========================================================End of Strings


==Arrays================================================================
A. Introduction
	1. Arrays are ordered lists of information of a certain type
	2. Arrays can be multidimensional, like a spreadsheet
	3. Arrays create information in consecutive spaces in memory
	4. You can change the individual elements of the array but you cannot change the length
	5. Arrays are initialized just like primatives, but with square brackets following:
//example///////////////////////////////////////////////////////////////
int a[] = {1,2,3,4,5}; //creates an array of 5 integer elements with values as shown
int a[5] = {0}; //creates an array with 5 integer elements, but all values are initialized to 0
int a[5]; // same as above: if you do not initalize what the elements are, they all start as 0
////////////////////////////////////////////////////////////////////////

B. Examples of use
	1. Arrays can be used to work with entire sets of data easily: the following program gives maximum, minimum, and mean of a set of data:
	2. note that that loop logic can be used to iterate through the loop, and elements called as a[i] behave just like primatives
//example///////////////////////////////////////////////////////////////
#include<iostream>
#include<cmath>
using namespace std;

int main(){

	int a[5] = {16,1,8,9,25};
	int max,min,sum;
	max=a[0];
	min=a[0];
	sum=0;

	for (int i =0;i<5;i++){
	//cout << a[i] <<endl;
		if (a[i] > max){
			max=a[i];
		}
		if (a[i] < min){
			min=a[i];
		}
		sum=sum+a[i];
	}
	cout << "Maximum value is: " << max <<endl;
	cout << "Minimum value is: " << min <<endl;
	float average = sum/5.0;
	cout << "Average value is: " << average ;

	return 0;
}
////////////////////////////////////////////////////////////////////////
C. Multiple-Subscripted Arrays
	1. Multiple Subscripts, or multiple dimensional arrays, are possible to create
	2. Think of these as a system having both rows and columns, etc.
	3. Initialized by slightly differently
	4. The following code asks a user for Rows and Columns, then allows the user to enter these values:
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <iomanip> //manipulates input/output, used for setw() function to make this pretty
using namespace std;

// this program prints out an array called 'b' as rows and columns
int main() {
	int rowInput, colInput;
	cout << "enter a value between 1 and 10 for rows: ";
	cin >> rowInput;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInput;
	}
	while( rowInput > 10 || rowInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> rowInput;
	}
	cout << "enter a value between 1 and 10 for columns: ";
	cin >> colInput;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInput;
	}
	while( colInput > 10 || colInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> colInput;
	}
	int b [rowInput][colInput];

	for (int row = 0; row < rowInput; row++) {
		for ( int col = 0; col < colInput; col++) {
			cout << "please enter value for (" << row << "," << col <<") :";
			cin >> b[row][col];
			while(cin.fail()) {	//error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> b[row][col];
			}
		}
	}

	for (int row = 0; row < rowInput; row++) {
		for (int col = 0; col < colInput; col++) {
			cout << setw(4) << b[row][col];
		}
		cout << endl;
	}
return 0;
}

////////////////////////////////////////////////////////////////////////

	5. This same logic can be used to create row or column sums and averages etc. or doing the sum, average, etc. of the entire table
/example////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <iomanip> //manipulates input/output, used for setw() function to make this pretty
using namespace std;

// this program prints out an array called 'b' as rows and columns
int main() {
	int rowInput, colInput;
	cout << "enter a value between 1 and 10 for rows: ";
	cin >> rowInput;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> rowInput;
	}
	while( rowInput > 10 || rowInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> rowInput;
	}
	cout << "enter a value between 1 and 10 for columns: ";
	cin >> colInput;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> colInput;
	}
	while( colInput > 10 || colInput <= 0) {
                cout << "Error: enter rows between 1 and 10: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> colInput;
	}
	int b [rowInput][colInput];

	for (int row = 0; row < rowInput; row++) {
		for ( int col = 0; col < colInput; col++) {
			cout << "please enter value for (" << row + 1 << "," << col + 1 <<") :";
			cin >> b[row][col];
			while(cin.fail()) {	//error handling loop
				cout << "Error: invalid input" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> b[row][col];
			}
		}
	}

	for (int row = 0; row < rowInput; row++) {
		for (int col = 0; col < colInput; col++) {
			cout << setw(4) << b[row][col];
		}
		cout << endl;
	}
	cout << endl;

	//include a variable for column and total sums and averages
	int colSum, rowSum, totalSum = 0;
	float colAvg, rowAvg = 0.0;

	//column-wise sums and averages and adding to sums
	for (int col = 0; col < colInput; col++) {
		for (int row = 0; row < rowInput; row++) {
			colSum = colSum + b [row][col];
		}
		totalSum = totalSum + colSum;
		cout << "The sum of column " << col + 1 << " is: " << colSum << endl;
		colAvg = float(colSum)/rowInput;
		cout << "The average of column " << col + 1 <<" is: " << colAvg << endl;
		//reset these to zero for the next loop
		colSum = 0;
		colAvg = 0;
	}

	//row-wise sums and averages
	for (int row = 0; row < rowInput; row++){
		for (int col = 0; col < colInput; col++){
			rowSum = rowSum + b[row][col];
		}
		cout << "The sum of row " << row  + 1 << " is: " << rowSum << endl;
		rowAvg = float(rowSum)/colInput;
		cout << "The average of row " << row + 1 << " is :" << rowAvg << endl;
		//reset to zero for next loop
		rowSum = 0;
		rowAvg = 0;
	}

	//totals
	cout << "The sum of all elements is: " << totalSum << endl;
	float totalAvg = totalSum / (rowInput * colInput);
	cout << "The average of all elements is: " << totalAvg << endl;
return 0;
}

////////////////////////////////////////////////////////////////////////
/*
*  To explain, the above code creates an two-dimensional array of a user provided size
*  It then allows the user to input each element of that array, then prints it so the user can see it
*  It then uses two sets of nested loops, to first display sums and averages of columns and rows within this array
*  During the column loops, it also creates a sum of all elements to display at the end, and compute the total elements average
*/
	6. If you have certain elements within an array and want to search for it, you can use boolean logic to get that from the array
	7. Logical steps for finding elements within an array:
		-> How to traverse the array?
		-> How are you going to determine if you found something?
		-> What should the program do if it doesn't find something?

//example///////////////////////////////////////////////////////////////
/*
 * this program creates an array then asks for the user for an input
 * if the input is in the array, it tells the user where it was found and counts how many times
 * if the input is not in the array, it tells the user it was never found
 * */
#include <iostream>
using namespace std;

int main(){
	int a[8] = {4,87,4,4,21,41,4,9};
	bool isThere = false;
	int counter = 0;

	int input;
	cout << "guess a number : ";
	cin >> input;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> input;
	}
	int value = input;

	for (int i = 0; i < 5; i++){
		//at each element of the array, it checks if value is equal to that element
		if (a[i] == value) {
			isThere = true; // makes sure if it found the number at least once then it doesn't need to say it didn't find it
			counter++;
			cout << "Found " << value << " at index: " << i << endl;
		}
	}
	//check the boolean, decide if number was found
	if (isThere == false) {
		cout << value << " was never found." << endl;
	}
	else {
		cout << "found " << value << " " << counter << " times" << endl;
return 0;
}
////////////////////////////////////////////////////////////////////////
D. Searching Arrays
	1. Problem: if you want to search an array of size n the complexity of the linear search is O(n) where each element has a compute time
	2. For very large linear arrays, this can give very long wait times
	3. Solution: Binary Search
		->  if we split the array we can only search for that instead
		-> this reduces the complexity of the search from O(n) to O(log2(n))
		-> this saves on resources and makes for better algorithms
	4. Binary Search only works if the array is sorted

E. Other issues with arrays
	1. sizeof() command does not return the number of elements in an array, but instead how many bits * # elements
		-> to get proper array length, easiest way is to return sizeof(array)/sizeof(array[0])
		-> hard-coding sizeof(array) divided by a static number is bad practice because variable sizes can change by processor type
//example///////////////////////////////////////////////////////////////
int a[4]; //the size of int on a 64bit processor is 4bits, but is 2bits on older systems
sizeof(a)/sizeof(a[0]); // this method works dynamically every time
sizeof(a)/4; // this is bad practice; would give double the size of the array on an older system
////////////////////////////////////////////////////////////////////////
F. Binary Search Logic
	1. consider a sorted list, such as: "1, 4, 8, 16, 18"
	2. each element has an index, starting 0: "0, 1, 2, 3, 4, 5"
	3. we are searching for 16 which is equal to v
	4. logical steps of the search:
		i.   let's call each leftmost index l (0) and each rightmost element r (5) and the middle m
		ii.  find a new m: m = l + ((r - l)/2); in this example 0 + ((5 - 0)/2)
		iii. in C++ integer logic, this is rounded; 5/2 = 2 = m
		iv.  if the value of element m is equal to 16 return m as the answer and stop
		v.   if the value of element m does not equal 18, then:
			-> if m < 18, then l is now m + 1
			-> if m > 18, then r is now m - 1
		vi. algorithm repeats from step i until m = 16
	5. you can place the entire algorithm such that it only runs if l < r, so that it does not overstep the array in searching
===========================================================End of Arrays


==Exercises=============================================================
	Exercise 1 - Difference between linear search and binary search exists as a level of complexity of the worse-case scenario
	of that search; for linear search this is O(n) whereas for binary search this is O(log2(n)) where n is number of elements and
	O is the computing time cost of each operation.

	Exercise 2 - C++ class string has a variable size during runtime, whereas C-style strings have fixed size; C-style strings must also
	end with '\0' whereas C++ class string understands where to end itself; finally, C++ class string can be easily concatenated

	Exercise 3 - getline() is used where a '\0' character would otherwise break input; for instance, if a name field had a space
	"Franz Jozef" a cin of this without getline() would truncate the input to "Franz".
// example /////////////////////////////////////////////////////////////
string Firstname;
cin << Firstname; //input "Franz Jozef" -> saved value "Franz"
getline(cin, Firstname); // input "Franz Jozef" -> saved value "Franz Jozef"
////////////////////////////////////////////////////////////////////////

	Exercise 4 -
		a. char s[] = "Kraut State University";
		   s[12]; // equals 'U'

		b. string example("It's been a very busy day");
		   example.replace(17,4,"sunny"); // replaces busy with sunny, forming string "It's been a very sunny day"

		c. string animal("Birds");
		   animal.insert(0, "Angry"); // inserts "angry" at position zero, yielding "Angry Birds"

		d. string game("March Madness")
		   game.substr(6,7) //starts at position 6 and finds the 7 next characters, forming string "Madness"

		e. string s1("Super");
		   s1.length(); //length is 5

	Exercise 5. Write a 1 dimensional array to add all positive elements:
		-> Code to enter values in main method
		-> Code to loop through list in main:
		-> for each element, call void sum_positive(a) to tell if a[i] is greater than 0, then add to sum; else do not
		-> finally, print out the sum
	example of the code which supports this logic is as follows:
//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//function of sum_positive only adds positive values
void sum_positive(int afunc[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
			cout <<afunc[i] << endl;
	}
	for (int i = 0; i < size; i++) {
		if (afunc[i] > 0) {
			sum = sum + afunc[i];
		}
	}
	cout << "The total of positive values is: " << sum << endl;
}

int main(){
	int arrInput = 0;
	//loop to take length of array
	cout << "Please enter list size: ";
	cin >> arrInput;
	while(cin.fail()) {	//error handling loop
		cout << "Error: invalid input! please try again: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> arrInput;
	}
	while(arrInput <= 0) {
                cout << "Error: please enter positive numbers only: " << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> arrInput;
	}
	int a[arrInput]; //creates array of length provided by user

	cout << "created a list with length of " << sizeof(a)/sizeof(a[0]) << "." << endl;

	//loop to take values from the user
	for (int i = 0; i < arrInput; i++) {
		cout << "please enter value for element " << i + 1 << " of the list: ";
		cin >> a[i];
		while(cin.fail()) {	//error handling loop
			cout << "Error: invalid input" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> a[i];
		}
	}

	//call sum positive
	sum_positive(a, arrInput);

	return 0;
}
////////////////////////////////////////////////////////////////////////
========================================================End of Exercises



==Finding Primes========================================================
A. Sieve of Eritophenes - logic
	1. Method to find prime numbers in a set of 100
	2. starts with assumption all numbers are prime
	3. first thing it does is remove 1 from the set; a prime number needs 1 and itself as a factor
	4. starting at values greater than one, one uses the square root of the number and checks if that is a factor of the number
B. Logic for finding primes without an array
//example///////////////////////////////////////////////////////////////
#include <cmath>
#include <iostream>
using namespace std;

int main() {
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
////////////////////////////////////////////////////////////////////////
C. Finding primes using an array
	1. create an array of all true (assume every number is prime)
	2. set 1 to false because of the definition of primes
	3. starting at 2, the smallest prime, move through array counting multiples of 2 and set to false
	4. find the next number greater than p not marked, then repeat steps using the same number
	5. stop at the square root of the list number (in this case 100) because there are no factors possible above this

//example///////////////////////////////////////////////////////////////
#include <cmath>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	bool prime[101];
	//this sets everything in prime to true
	memset(prime, true, sizeof(prime));
	//set 1 to false manually, given the definition of prime numbers
    prime[0] = false;
	prime[1] = false;
	//starting from 2, if the number is a multiple of it, set to false
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
	cout << "there are " << counter << " prime numbers  between 0 and 100" << endl;
	return 0;
}

////////////////////////////////////////////////////////////////////////
===================================================End of Finding Primes


==Pointers==============================================================
I. Introduction
	A. A pointer refers to a memory address and what is inside that address
		1. the memory address of any variable can be called as "&var"
	B. rather than having a data type, pointers hold memory addresses
		1. pointers have their own memory addresses
		2. the reference of the address of a pointer gives what is in the memory address
		3. pointer can be used to efficiently call many variables in sequence without copying the variables
		4. pointers can point to other pointers
//example///////////////////////////////////////////////////////////////
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
	cout << **ptr2 << endl; //prints what pointer2 is pointing to aka b = 10
	return 0;
}

////////////////////////////////////////////////////////////////////////
	C. when you pass variables between functions, you are using 'pass-by value', in which a new instance of a variable is created
		1. changes to the new variable do not update the initial variable
		2. tends to waste memory unless your original variables are important
	D. instead you can use pass-by reference, in which you point to the variable instead of copying it
		1. more frugal use of memory
		2. reduces amount of issues in passing types between functions
II. Pointers in Depth
	A. Pointer Variables
		1. the value of a pointer p is the address of variable a
		2. pointer to a pointer also works when declared with two dereferencing operators (**)
	B. Dereferencing operator (*)
		1. We can access to the value stored in variable pointed to by using the dereferencing operatior (*)
		2. declaring a pointer means on
	C. A pointer example
		1. a value is declared for a, this creates a memory address for a
		2. doubleit() takes an integer and a memory reference as arguments
		3. we pass 9 and a's memory address to doubleit(), which then sets a to 18 using a pointer (2 * 9)
//example///////////////////////////////////////////////////////////////
void doubleIt(int x, int * p)
{
	*p = 2 * x;
}
int main( int argc, const char * argv[])
{
	int a = 16; //memory address is created for a, and it is set to 16
	doubleIt( 9, &a) //during runtime, x is set to 9, and p is set to 18, p points to &a, so a is now 18
	return 0;
}
////////////////////////////////////////////////////////////////////////
=========================================================End of Pointers


==Bubble Sort===========================================================
I. Introduction
	A. Bubble sort is one of the most basic algorithims to sort an array, and can be implemented without pointers
	B. Disadvantage: complexity of bubble sort is O(n^2) bad efficiency for large lists
	C. It is a comparison sort: it checks two elements and swaps them if they are not in correct order
	D. Bubble sort continues to loop through the list until the list is sorted, creating several "passes"

//example///////////////////////////////////////////////////////////////
int main () {
	int a[] = {3,2,1};
	int size = sizeof(a)/sizeof(a[0]) //find true length of a
	//before sorting
	for ( int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for(i=1;i<size;++i){
		for(j=0;j<(size-i);++j){
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	//after sorting
	for ( int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////
II. Optimization
	A. Bubble Sort can be optimized further
	B. For each pass, the number of elements already sorted at the end of the array is equal to the number of passes
	C. Therefore, we can make bubble sort more efficient by reducing number of operations per pass by the number of already sorted items
		1. inner loop traditionally runs for (size - 1) loops
		2. instead use (size - 1 - i) loops
	D. If the list does not swap at all in a pass, it does not need to continue (early swap)
		1. we can create a boolean to tell whether or not a swap has occured in the pass
		2. if the boolean is not set to false, it breaks the loop because no swaps have occured
	E. Bubble Sort still somewhat crude and only suitable for small lists; worst case scenario is still O(n^2) complexity

Compare the examples below
//example of standard bubble sort///////////////////////////////////////
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
	cout << "sorted list in " <<  counter << " loops!" << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////

//example of fully optimized Bubble Sort////////////////////////////////
#include <iostream>
using namespace std;

int main(){
	int a[] = {88, 53, 46, 23, 112, 45, 68, 29, 222};
	int temp = 0;
	int size = sizeof(a)/sizeof(a[0]);//find true length of a
	bool swap = true;
	int counter = 0;

		for ( int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for(int i=1;i<size;++i){
		for(int j=0;j<(size-i );++j){
			swap = true;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap = false;
				counter++;
			}
		}
		if (swap == true){
			break;
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
////////////////////////////////////////////////////////////////////////
======================================================End of Bubble Sort

==Merge Sort============================================================
I. Introduction
	A. There is a better method of sorting by splitting the original list into a binary tree
	B. Merge Sort has O(nlog(n)) complexity compared to O(n^2) of bubble sort
	C. Consider the following
//Binary Tree///////////////////////////////////////////////////////////
original list: 5 4 3 2 1 0

split into elements with max size of two
            5 4 3 2 1 0
	    /	     \
	   /          \
	  V            V
       5 4 3         2 1 0
        / \           / \
       /   \         /   \
      V     V       V     V
    5  4 |  3   |   2  1  |  0

then, each sublist is sorted and merged upward
original lists:           5  4 |  3   |   2  1  |  0
sort elements:            4  5 |  3   |   1  2  |  0
sort lists:               3    | 4  5 |   0     |  1  2
merge sorted lists:       3  4  5     |   0   1   2
sort lists:               0  1  2     |   3   4   5
merge sorted lists:       0  1  2  3  4  5
done
////////////////////////////////////////////////////////////////////////
=======================================================End of Merge Sort


==Selection Sort========================================================
I. Introduction
	A. Repeat until no unsorted elements remain
		1. Search the unsorted part of the data to find the smallest value
		2. swap the smallest found value with the first element of the unsorted part
	B. Complexity is still O(n^2) but with different logic
II. Pseudocode
	A. Begin with creating a variable and setting the first element of the array
	B. search through array using a loop and if a new minimum is found, then save its index
	C. At the end of the loop, swap the index found with the current i of the loop (0 for first pass, and so on)
	D. Whereas bubble sort puts items at the end of the list, selection sort begins at the start of the array

//example///////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////
===================================================End of Selection Sort


==Sorting with Functions=====================-==========================
I. Considering Bubble and Selection Sort
	A. algorithms can be reduced into functions
	B. in previous code we:
		1. declared variables
		2. displayed the list
		3. performed our sort
			a. swaps performed inside the sort
		4. displayed the list again
	C. Consider the following:
//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

void printArray(int array[], int length){
	for ( int i = 0; i < length; i++) {
		cout << array[i] << " ";
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
	printArray(a, size);
	bubbleSort(a, size);
	//after sorting
	printArray(a, size);
	return 0;
}
////////////////////////////////////////////////////////////////////////
===========================================End of Sorting With Functions


==Object Oriented Programming===========================================
I. Introduction to Classes
	A. Class Definition
		1. The class is the cornerstone of C++
			- it makes possible encapsulation, data hiding, and inheritance
		2. Type
			- concrete representation of a concept: AKA float with operations such as -,+,*,/
		3. Class
			- class is a user defined type
			- consists of both data and methods
			- defines properties and behavior of that type
			- an object is an instance of a class much like a variable is an instance of a primitive like int or string
		4. object oriented programming allow for:
			- types matching program concepts: aka video game programming
			- higher code reuse
			- objects can be used to save program state more easily
			- allow for several teams to work on classes rather than the entire program
			- allow for functions and methods to be made public, while data hidden as private
			- compiler can detect illegal uses of types
			- code analysis is easier
	B. Class Example
//example///////////////////////////////////////////////////////////////
#include <iosteam>
using namespace std;


class leftHand{
	public:
		void pick(){
			cout << "Left hand pick initiated: " << endl;
		}
}; // classes end in semicolon

class rightHand{
	public:
		void pick(){
			cout << "Right hand pick initiated: " << endl;
		}
};

int main(){
	 //create new object of leftHand class and save it as obj1
	leftHand obj1;
	//call pick for obj
	obj1.pick();
	rightHand obj2;
	obj2.pick();
	return 0;
}
////////////////////////////////////////////////////////////////////////

	C. Objects
		1. An object is an instance of a class
		2. When as class is defined, no memory is allocated until the object is created in main()
		3. in the previous example, obj1 and obj2 are the variable names for the new objects
		4. the data members and member functions of a class are accessed via object instances with a dot // objectName.function();
		5. variables can be passed to data within objects using functions so that private data is accessed with public methods
		6. Variables within an object should be private; whreas methods are used to get and set that data
			- improves consistency of code when multiple objects are created
			- ensures exclusive data access to class members
			- protects object integrity by preventing unintended or intended changes

//example///////////////////////////////////////////////////////////////
class Print{
	private:
		string name;
	public:
		void setName(string x){
			name = x;
		}
		string getName(){
			return name;
		};
};
////////////////////////////////////////////////////////////////////////

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class rectangle{
	private:
		float len,wid;
	public:
		void setDimensions(float x, float y){
			len = x;
			wid = y;
		}
		float getLength(){
			return len;
		}
		float getWidth(){
			return wid;
		}
		float calcArea(){
			float area = len * wid;
			return area;
		}
		float calcPerimeter(){
			float perimeter = len * 2 + wid * 2;
			return perimeter;
		}
};

int main(){
	rectangle obj;
	obj.setDimensions(5, 12);
	cout << "created rectangle with length of " << obj.getLength() << " and width of " << obj.getWidth() << endl;
	cout << "area of the rectangle is: " << obj.calcArea() << endl;
	cout << "perimeter of the rectangle is: " << obj.calcPerimeter() << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////
II. Static variables
	A. Static variables remember the value
	B. useful when used in a function because they do not go away after a function is called
	C. static variables are thus function-specific variables that are not removed after they are called
		1. can be used to remember state of a system
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

void demo(){
	static int count = 0; //static variable does not get removed after function is called
	count << count << " ";
	count++;
}

int main(){
	for (int i=0; i<5; i++){
		demo();
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////

III. Constructors in C++
	A. A constructor is a member of a class which initializes objects of that class
		1. constructors are automatically called when the object is created
			- even if you didn't call it explicitly, C++ creates a default constructor
		2. special member function of that class
	B. Constructors are different from normal functions
		1. constructor has the same name as the class itself
		2. no return type
		3. a constrcutor is always automatically created when an object is created
		4. if we do not specify a constructor, the C++ compiler generates a constructor for that class to make objects of that class
	C. Creating constructor methods
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Hello{
	public:
		//this is the constructor method for class Hello
		Hello(string s){
			cout << "Hello, ";
			setName(s);
		}

		void setName(string t){
			name = t;
		}

		string getName(){
			return name;
		}

	private:
		string name;
};


int main(){
	//constructor called
	Hello obj1 =  Hello("John");
	cout << obj1.getName() << endl;
	//alternate use of constructor
	Hello obj2("Jeff");
	cout << obj2.getName() << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////
	D. Constructor Overloading
		1. Constructors can be 'overloaded' by adding more input types to a given constructor
		2. as such, multiple constructors can be added to a class to handle more types of input
//example///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Hello{
	public:
		//this is the constructor method for class Hello
		Hello(string s){
			cout << "Hello, ";
			setName(s);
		}
		Hello(string a, string b){
			cout << "Hello, ";
			setFName(a);
		}
		void setFName(string t){
			firstName = t;
		}
		void setFullName(string x, string y){
			firstName = x;
			lastName = y;
			fullName = firstName + lastName;
		}

		string getName(){
			return firstName;
		}
		string getFullName(){
			return fullName;
		}

	private:
		string firstName;
		string lastName;
		string fullName
};
////////////////////////////////////////////////////////////////////////
	E. Destructors and Copy Constructors
		1. Copy constructors copy objects
			- create new copies (as addresses and variables) of variables from the copied object
			- be aware: pointers are not properly copied by default; instead, pointers should be converted
			- in order to avoid a 'shallow copy' of a pointer in a constructor, you need to create a copy constructor
		2. Destructors are used to copy over individual data fields between constructors by keeping these within the same class

======================================End of Object Oriented Programming


==Copy Constructors=====================================================
I. the situation
	A. when constructors are copied, variables are copied to a new memory location
	B. however, when pointers within a constructor are copied, the memory location pointed to remain the same
	C. this leads to potential situations where memory on the heap is changed leaving the new pointer referencing garbage data
II. the solution
	A. create a constructor which explicitly copies the values over in the class

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class point{
	private:
		int x, y;

	public:
		point(int a, int b){
			x = a;
			y = b;
		}

		//declaring syntax for copy constructor
		point(const point &p2){
			x = p2.x;
			y = p2.y;
		}

		int getX(){
			return x;
		}

		int getY(){
			return y;
		}


};

int main(){

	point p1(10, 15); //invoking a normal constructor
	cout << "P1.x= " << p1.getX() <<endl  << "P1.y= " << p1.getY() << endl;

	point p2  = p1; //invoking a copy constructor
		cout << "P2.x= " << p2.getX() <<endl  << "P2.y= " << p2.getY() << endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////
C. Stack vs Heap
	A. everything is a typically on the stack
		1. imagine a deck of cards with one line of code on each card
		2. how the program actually works in processor and memory
	B. stacks are Last-In, First Out (LIFO)
	C. if you wanted to store a lot of information dynamically heap is instead used
		1. large amount of memory used for a specific task
		2. explicitly declared, and then accessed by the stack
		3. Heap items are declared with the 'new' keyword
			-> copy constructor needed to ensure pointers are changed when objects are copied, as per usual
			-> when a heap memory program terminates, that memory remains in the RAM until it is changed unless it is explicitly deleted
//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Base{
	private:
                int *ptr;
                int val;

        public:

		Base(){
			ptr = new int;
                        //val;
                }

                //copy constructor
                Base(const Base &b2){
                        ptr = new int;
                        *ptr = *b2.ptr;
                        val = b2.val;
                }

                void setPtr(int p){
                        *ptr = p;
                }
                void setVal(int q){
                        val = q;
                }
                int getPtr(){
                        cout << ptr << " is the address of the ptr " << endl;
                        return *ptr;
                }
                int getVal(){
                        cout << &val << " is the address of the value" << endl;
                        return val;
                }
};

int main(){
	Base b1;
        b1.setPtr(10);
        b1.setVal(20);

        cout << endl << b1.getPtr();
        cout << endl << b1.getVal();
        Base b2 = b1; //copy constructor called
        cout << endl << b2.getPtr();
        cout << endl << b2.getVal();
        cout << endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////
================================================End of Copy Constructors


==Cube Constructor======================================================
A. one constructor for exactly one input to create cubes
B. one constructor for cuboids with different side lengths

//example///////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Calculate {
	private:
		int l, w, h;
	public:
		Calculate(int a){
			l = a;
			getCube();
		}
		Calculate(int a, int b, int c){
			l = a;
			w = b;
			h = c;
			getCuboid();
		}

		int getCube(
			return l * l * l;
		}

		int getCuboid(){
			return l * w * h;
		}
};

int main(){
	Calculate obj1(10); //calculates a cube with all sides 10
	cout << "the volume of the cube is: " << obj1.getCube() << endl;
	Calculate obj2(10,20,30); //calculates a cuboid with different side lengths
	cout << "the volume of the cuboid is: " << obj2.getCuboid() << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////

=================================================End of Cube Constructor


==Inheritance===========================================================
I. Inheritance explained
	A. General classes can define a non-specific class; for example consider a class polygon
	B. constructors of that class can inherit the properties of polygon, but extend it
		1. in the same example, class polygon is extended by constructors triangle and rectangle
		2. the polygon superclass defines properties for the class constructors which are inherited
	C. access given to subclasses (public, private, or protected) are also inherited
		1. whatever is declared as public from superclass is inherited as public in subclass
		2. whatever is declared as protected from superclass is inherited as public in subclass
		3. whatever is declared as private from subclass is inherited by subclass but is not accessible
II. Why use inheritance?
	A. mechanism for building class types from existing class types
	B. defining new classes via
		1. augmentation
		2. specialization
	C. saves lines of code on dervived subclasses when defined classes exist

//example///////////////////////////////////////////////////////////////
class Polygon{
	protected:
		int numVertices;
		float *xCoord, float *yCoord;
	public:
		void set(float *x, float *y, int nV);
};

//this class inherits everything from the above class, as such class Rectangle "extends" Polygon
class Rectangle : public Polygon {
	public:
		float area;
};
////////////////////////////////////////////////////////////////////////


//example///////////////////////////////////////////////////////////////
class Point{
	protected:
		int x,y;
	public:
		void set(int a, int b);
};

class Circle : public Point{
	private:
		double r;
};

class 3DPoint : public Point {

	private:
		double z; //sphere can not access this variable
};

class Sphere : public 3DPoint {
	private:
		double r;
};
////////////////////////////////////////////////////////////////////////
======================================================End of Inheritance


