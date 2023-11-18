#include <iostream>
using namespace std;

int D[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
	int y, w;
	bool isNone = true;
	cin >> y >> w;
	if (y % 100 == 0){
		if (y % 400 == 0) D[2] = 29;
		else D[2] = 28;
	} else {
		if (y % 4 == 0) D[2] = 29;
		else D[2] = 28;
	}
	// 暴力模拟
	int m = 1, d = 0, we = w-1;
	while (m != 12 || d != 30){
		d++;
		we++;
//		cout << m << ' ' << d << ' ' << we << endl;
		if (d == 13 && we == 5){
			cout << m << endl;
			isNone = false;
		}
		if (we >= 7) we = 0;
		if (d >= D[m]){
			d = 0;
			m++;
		}
	}
	if (isNone) cout << "None" << endl;
	
	// 数学计算
//	int sum = 0;
//	for (int i = 1; i <= 12; i++){
////		cout << (sum + 12 + w) % 7 << endl;
//		if ((sum + 12 + w) % 7 == 5){
//			cout << i << endl;
//			isNone = false;
//		}
//		sum += D[i];
//	}
//	if (isNone) cout << "None" << endl;
	
	return 0;
}