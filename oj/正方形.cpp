#include <iostream>
using namespace std;

int main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int xd = x1-x2;
	int yd = y1-y2;
	cout << x2+yd << ' ' << y2-xd << ' ' << x1+yd << ' ' << y1-xd << endl;
	return 0;
}