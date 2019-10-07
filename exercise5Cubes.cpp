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
