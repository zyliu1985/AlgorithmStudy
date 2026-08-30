#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10009],b[10009];

int main (){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1;i <= m;i++){
		cin >> b[i];
	}
	if (m == 0){
		int sum = 0;
		for (int i = 1;i <= n;i += 2){
			sum += a[i];
		}
		int sum2 = 0;
		for (int i = 2;i <= n;i += 2){
			sum2 == a[i];
		}
		if(sum > sum2){
			cout << sum << endl;
		}else{
			cout << sum2 << endl;
		}
	}
	return 0;
}
