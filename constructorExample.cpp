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
