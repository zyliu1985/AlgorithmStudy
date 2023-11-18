#include <iostream>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool flag[13];
bool run(int x){
	if (x % 100 == 0) return x % 400 == 0;
	else return x % 4 == 0;
}
bool none(){
	for (int i = 1; i <= 12; i++){
		if (flag[i]) return false;
	}
	return true;
}

int main(){
	int y, w;
	bool r;
	cin >> y >> w;
	if (run(y)) r = true;
	else r = false;
	for (int m = 1; m <= 12; m++){
		for (int d = 1; d <= month[m]+(m == 2 && r); d++){
			if (w == 5 && d == 13 && !flag[m]){
				cout << m << endl;
				flag[m] = true;
			}
			w++;
			if (w > 7) w = 1;
		}
	}
	if (none()) cout << "None" << endl;
	return 0;
}