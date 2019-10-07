#include <iostream>
using namespace std;

class Seminar { 
	private:
	
	int time;
	
	public:
		Seminar(){ //function 1
			time = 30; 
			cout << "Seminar starts now" << endl; 
		} 
		void lecture(){ //function 2
			cout << "Lectures in the seminar on" << endl; 
		} 
		Seminar(int duration){ //function 3
			time = duration;
			cout << "Seminar starts now" << endl; 
		} 
		~Seminar(){ //function 4
			cout << "Thanks" << endl; 
		}
};

int main(){
	//invoking constructor shown in function 1
	Seminar(); 
	//invoking constructor shown in function 3
	Seminar b(60);

	return 0; 
}
