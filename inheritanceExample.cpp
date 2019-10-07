#include <iostream>
using namespace std; 

class PPP { 
	int H;
	protected : 
		int S; 
	public : 
		void input (int a);
		
		void out();
 }; 
 
class QQQ : private PPP { 
	int T; 
	protected : 
		int U; 
	public : 
	void indata(int, int);
	
	void outdata(); 
	
}; 

class RRR : public QQQ { 
	int M; 
	public : 
		void disp(){
			cout << "M = " << M << endl;
			cout << "U = " << U << endl;
		}
 }; 
 
int main(){
	RRR r();
	r.disp();
	return 0;
}
