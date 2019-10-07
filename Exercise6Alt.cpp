#include <iostream>
using namespace std;

class REPORT{
	private:
                int ando;
                char name[20];
                float marks[5];
                float average;
                float sum = 0;

        public:

               	void READINFO(){
                        do{
                           	cout << "Please enter the admisssion number: " << endl;
                                cin >> ando;
                        }while (ando < 1000 || ando > 9999);

                        cout << "Enter name: " << endl;
                        cin >> name;
                        cout << "Enter marks in..." << endl;
                        for( int i = 0; i < 5; i++){
                                cout << "Subject " << i + 1 << ": ";
                                cin >> marks[i];
                        }
                }

                void GETAVG(){
                        for (int i = 0; i < 5; i++){
                                sum = sum + marks[i];
                        }
                        average = sum/5;
                }

                void DISPLAYINFO(){
                        cout << "The admission number is: " << ando <<endl;
                        cout << "The student's name is: " << name << endl;
                        for( int i = 0; i < 5; i++){
                                cout << "Subject " << i + 1 << ": " << marks[i] << endl;
                        }
                        cout << "The average is: " << average << endl;
                }

};

int main() {
	REPORT obj;
    obj.READINFO();
    obj.GETAVG();
    cout << endl;
    obj.DISPLAYINFO();
    return 0;
}
