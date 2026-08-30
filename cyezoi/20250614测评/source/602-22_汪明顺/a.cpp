#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
const int M = 10;
char a[N][M];
int date[M];
int n, maxn = LONG_LONG_MIN, cnt = 0;
signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin >> a[i][j];
			if(a[i][j] == 'Y'){
				date[j]++;
				if(date[j] == maxn)
					cnt++;
				else if(date[j] > maxn){
					maxn = date[j], cnt = 1;
				}
			}
		}
	}
	for(int i = 1; i <= 5; i++){
		if(date[i] == maxn){
			cnt--;
			cout << i;
			if(cnt > 0)
				cout << ',';
		}
	}
	cout << '\n';
	return 0;
}
