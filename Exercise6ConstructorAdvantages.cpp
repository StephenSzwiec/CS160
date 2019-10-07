#include <iostream>
using namespace std;

class rectangle {
	private:
		float x, y;
		bool isSquare = false;
	protected:
		float area;
		float perimeter;
	public: 
		rectangle() { //advantage 1: overwriting the default constructor 
			x = 0;
			y = 0;
			area = x * y;
			perimeter = 2 * x + 2 * y;
		}
		rectangle(int a, int b){ //advantage 2: overloading constructors for different effects
			x = a;
			y = b; 
			area = x * y;
			perimeter = 2 * x + 2 * y;
		}
		rectangle(int a){
			x = a;
			y = a; 
			area = x * y;
			perimeter = 4 * x;
			isSquare = true;
		}
		float getPerimeter(){
			return perimeter;
		}
		float getArea(){
			return area;
		}
		bool determineSquare(){
			return isSquare; 
		}
};
