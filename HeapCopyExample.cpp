#include <iostream>
using namespace std;

class Base{
	private:
                int *ptr;
                int val;

        public:

               	Base(){
                       	ptr = new int;
                        //val;
                }

                //copy constructor
                Base(const Base &b2){
                        ptr = new int;
                        *ptr = *b2.ptr;
                        val = b2.val;
                }

                void setPtr(int p){
                        *ptr = p;
                }
                void setVal(int q){
                        val = q;
                }
                int getPtr(){
                        cout << ptr << " is the address of the ptr " << endl;
                        return *ptr;
                }
                int getVal(){
                        cout << &val << " is the address of the value" << endl;
                        return val;
                }
};

int main(){
	Base b1;
        b1.setPtr(10);
        b1.setVal(20);

        cout << endl << b1.getPtr(); 
        cout << endl << b1.getVal();
        Base b2 = b1; //copy constructor called
        cout << endl << b2.getPtr();
        cout << endl << b2.getVal();
        cout << endl;

	return 0;
}
