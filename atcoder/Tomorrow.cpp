#include <iostream>
using namespace std;

int main(){
	int M, D;
	cin >> M >> D;
	int y, m, d;
	cin >> y >> m >> d;
	d++;
	if (d > D){
		d = 1;
		m++;
	}
	if (m > M){
		y++;
		m = 1;
	}
	cout << y << ' ' << m << ' ' << d << endl;
	return 0;
}