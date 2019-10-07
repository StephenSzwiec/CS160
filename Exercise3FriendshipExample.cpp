#include <iostream>
using namespace std; 

class example { 
	private:
	int a;
	public : 
		example(){
			a = 0;
		}
		example (int x){
			a = x; 
		}
	//class called friendo can access private variables within example
	friend class friendo; 
 }; 

class friendo {
	public:
		//access the private variable of class example with method and print it 
		void getA( example& o){
			cout << o.a << endl; 
		}
};
 
int main(){
	example obj1(25);
	friendo obj2; 
	obj2.getA(obj1);
	return 0;
}
