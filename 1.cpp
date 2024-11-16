#include <iostream>
using namespace std;

int main(int x){
	if (x == 1) return 1;
	return main(x - 1) * x;
}
