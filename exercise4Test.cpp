#include <iostream>
using namespace std;

class Test { 
	char paper[20]; 
	int marks;
	public:
		Test (){ // Function 1 
			strcpy (paper, "Computer");
			marks = 0; 
		}
		Test (char p[]){ // Function 2 
			strcpy(paper, p);
			marks = 0;
		} 
		Test (int m){ // Function 3
			strcpy(paper,"Computer");
			marks = m;
			} 
		Test (char p[], int m) { //Function 4
			 strcpy (paper, p);
			 marks = m;
		}
};

main(){
	//creating global variables 
	const int perfect = 100; 
	char input[] = {'H','e','l','l','o','\n'};
	//invoking the default constructor function 1
	Test test1 = Test();
	//invoking the constructor for function 2
	Test test2 = Test(input);
	//invoking the constructor for function 3
	Test test3(perfect);
	//invoking the constructor for function 4
	Test test4(input, perfect);
	return 0;
}

