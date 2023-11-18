#include <iostream>
using namespace std;

namespace gg{
	void b(){
		cout << 'b' << endl;
		return;
	}
	void a(){
		cout << 'a' << endl;
		b();
		return;
	}
	
}

int main(){
	gg::a();
	return 0;
}