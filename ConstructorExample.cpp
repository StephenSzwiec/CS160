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
	return 0;
}
