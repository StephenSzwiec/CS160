#include <iostream>
using namespace std;

class REPORT{
	private:
		int ando[4];
		char name[20];
		float marks[5];
		float GETAVG(){
			float sum;
			for (int i = 0; i < 5; i++){
				sum = sum + marks[i];
			}
			return (sum / 5); 
		}
		float average;
		
	public:
	
		void READINFO(int a[], char n[], float m[]){
			for(int i = 0; i < 4; i++){
				ando[i] = a[i]; 
			}
			for(int i = 0; i < 20; i++){
				name[i] = n[i];
			}
			for(int i = 0; i < 5; i++){
				marks[i] = m[i];
			}
			average = GETAVG();
		}

		void DISPLAYINFO(){
			cout << "#### STUDENT REPORT ####" << endl;
			cout << "Admission Number: ";
			for(int i = 0; i < 4; i++){
				cout << ando[i];
			}
			cout << endl;
			cout << "Name: ";
			for(int i = 0; i < 20; i++){
				cout << name[i];
			}
			cout << "Marks: " << endl;
			for(int i = 0; i < 5; i++){
				cout << "Test " << i+1 << ": " << marks[i] << endl;
			}		
			cout << "Average Grade: " << average << endl; 
		}
};

int main() {
	int x[4] = {1,3,3,7};
	char y[20] = {'H','e','l','l','o','\n'};
	float z[5] = {95, 70, 0, 80, 30};
	REPORT r = REPORT();
	r.READINFO(x,y,z);
	r.DISPLAYINFO();	

	return 0;
}
