#include <iostream>
using namespace std;

int a[500005], d[500005];

int main(){
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		d[i] = a[i] - d[i-1];
		if(i == 2) {
			sum = d[2];
		}
		for(int j = 1; j < i; j ++) {
			if (i == 2 && j == 1) continue;
			sum -= a[i] - a[j];
		}
	}
//	int sum = d[2];
//	for (int i = 2; i <= n; i++){
//		for (int j = 1; j < i; j++){
//			if (i == 2 && j == 1) continue;
//			sum -= (a[i] - a[j]);
//		}
//	}
	cout << sum << endl;	
}