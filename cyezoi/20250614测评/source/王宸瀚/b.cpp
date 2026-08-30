#include <bits/stdc++.h>
using namespace std;
int n;
int a[4][200009];
int c;
long long f(int x,int y){
	long long res = 0;
	if(x == 1){
		if(a[x][y-1]){
			res++;
		}
		if(a[x][y+1]){
			res++;
		}
		if(a[x+1][y]){
			res++;
		}
		return res;
	}else{
		if(a[x][y-1]){
			res++;
		}
		if(a[x][y+1]){
			res++;
		}
		if(a[x-1][y]){
			res++;
		}
		return res;
	}
}
int main (){
	cin >> n;
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j]){
				c++;
			}
		}
	}
	if (c == 2 * n){
		cout << (n/2+2)*2 << endl;
		return 0;
	}
	long long sum = 3*c;
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			if (a[i][j]){
				sum -= f(i,j);
			}
		}
	}
	cout << sum << endl;
	return 0;
}
