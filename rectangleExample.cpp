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
