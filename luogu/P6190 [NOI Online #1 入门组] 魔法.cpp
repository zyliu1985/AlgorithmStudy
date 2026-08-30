#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
long long w[205][205];
long long calc1[105][105];
long long lst[2][105][105];
bool now;
void floyd(){
	for (int k = 1; k <= 2*n; k++)
		for (int i = 1; i <= 2*n; i++)
			for (int j = 1; j <= 2*n; j++)
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			calc1[i][j] = min(w[i][j], w[i][j+n]);
}
void solve(int x){
	
	if (x == 1){
		now = !now;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				lst[now][i][j] = calc1[i][j];
	} else if (x & 1){
		solve(x-1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				lst[!now][i][j] = 1e18;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					lst[!now][i][j] = min(lst[!now][i][j], lst[now][i][k] + calc1[k][j]);
		now = !now; 
	} else {
		solve(x/2);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				lst[!now][i][j] = 1e18;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					lst[!now][i][j] = min(lst[!now][i][j], lst[now][i][k] + lst[now][k][j]);
		now = !now; 
	}
}
void solve0(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				w[i][j] = 1e18;
	for (int i = 1; i <= m; i++){
		long long a, b, t;
		cin >> a >> b >> t;
		w[a][b] = min(w[a][b], t);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
	cout << w[1][n] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (k == 0){
		solve0();
		return 0; 
	} 
	for (int i = 1; i <= 2*n; i++)
		for (int j = 1; j <= 2*n; j++)
			if (i != j)
				w[i][j] = 1e18;
	for (int i = 1; i <= m; i++){
		long long a, b, t;
		cin >> a >> b >> t;
		w[a][b] = min(w[a][b], t);
		w[a+n][b+n] = min(w[a+n][b+n], t);
		w[a][b+n] = min(w[a][b+n], -t);
	}
//	for (int i = 1; i <= 2*n; i++){
//	 	for (int j = 1; j <= 2*n; j++)
//	 		cout << w[i][j] << ' '; 
//		cout << '\n';
//	}
	floyd();
//	for (int i = 1; i <= 2*n; i++){
//	 	for (int j = 1; j <= 2*n; j++)
//	 		cout << w[i][j] << ' '; 
//		cout << '\n';
//	}
//	for (int i = 1; i <= n; i++){
//	 	for (int j = 1; j <= n; j++)
//	 		cout << calc1[i][j] << ' '; 
//		cout << '\n';
//	}
	solve(k);
	cout << lst[now][1][n] << '\n';
	return 0;
}

