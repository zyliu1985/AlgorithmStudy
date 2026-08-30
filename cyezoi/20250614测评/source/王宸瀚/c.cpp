#include <bits/stdc++.h>
using namespace std;
int n,a[5009];
const int INF = 1e9;
void f(int x){
	if (x == 1){
		cout << 0 << ' ';
		return;
	}
	int i = 1,j = x,b = INF,c = i,d = j,sum = 0;
	for (int k = 1;k  <= n-x+1;k++,i++,j++){
		c = i,d = j;
		sum = 0;
		if (x %2 == 1){
			for (int l = 1;l <= (x+1)/2;l++,c++,d--){
				sum += abs(a[c]-a[d]);
			}
			if (sum < b){
				b = sum;
			}
		}else{
			for (int l = 1;l <= x/2;l++,c++,d--){
				sum += abs(a[c]-a[d]);
			}
			if (sum < b){
				b = sum;
			}
		}
	}
	cout << b << ' ';
	return;
}
int main (){
	cin >> n;
	for (int i  = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		f(i);
	}
	return 0;
}
