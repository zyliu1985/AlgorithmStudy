#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010;
int A[N], B[N];
int sum[N];
int n, m, ans;
bool vis[N];
signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> B[i];
	if(m == 0){
		for(int i = 1; i <= n; i++)
			sum[i] = max(sum[i - 2] + A[i], sum[i - 1]);
		ans = sum[n];
	}
	else{
		for(int i = 0; i <= n; i++){
			memset(sum, 0, sizeof(sum));
			int tmp[N], cnt = 0;
			for(int j = 1; j <= i; j++)
				tmp[++cnt] = A[j];
			tmp[++cnt] = B[1];
			for(int j = i + 1; j <= n; j++)
				tmp[++cnt] = A[j];
			for(int j = 1; j <= n + 1; j++)
				sum[j] = max(sum[j - 2] + tmp[j], sum[j - 1]);
			ans = max(ans, sum[n + 1]);
		}
	}
	cout << ans << '\n';
	return 0;
}
