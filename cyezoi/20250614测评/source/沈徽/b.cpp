#include <bits/stdc++.h>
using namespace std;
int n,ans = 0,c[5][200010];
int main(){
	cin >> n;
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			cin >> c[i][j];
			if (c[i][j] == 1) ans += 3;
		}
	}
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			if (c[i][j] == 1){
				if (c[i][j-1] == 1) ans -= 1;
				if (c[i][j+1] == 1) ans -= 1;
				if (c[i-1][j] == 1) ans -= 1;
				if (c[i+1][j] == 1) ans -= 1;
			}
		}
	}
	cout << ans;
}
