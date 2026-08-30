#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int a[N][N], n;
int height[N];
signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> height[i];
		for(int j = 1; j <= i; j++)
			a[j][i] = a[i][j] = abs(height[i] - height[j]);
	}
	for(int i = 1; i <= n; i++){
		int ans = LONG_LONG_MAX;
		for(int j = 1; j <= n - i + 1; j++){
			int sum = 0;
			int mid = (j + j + i - 1) >> 1;
			for(int k = j; k <= mid; k++)
				sum += a[k][j + i - (k - j + 1)];
			ans = min(ans, sum);
			if(ans == 0)
				break;
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}
