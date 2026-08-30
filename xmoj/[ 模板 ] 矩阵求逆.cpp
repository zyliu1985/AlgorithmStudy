#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[405][805];
const int mod = 1e9 + 7;
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
int inv(int x){
	return qpow(x, mod - 2);
}
void mul_rank(int rk, int c){
	for (int i = 1; i <= 2 * n; i++)
		a[rk][i] = a[rk][i] * c % mod;
}
void add_rank(int from, int to, int c){
	for (int i = 1; i <= 2 * n; i++)
		a[to][i] = (a[to][i] + a[from][i] * c % mod) % mod;
}
void swap_rank(int x, int y){
	for (int i = 1; i <= 2 * n; i++)
		swap(a[x][i], a[y][i]);
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	for (int i = 1; i <= n; i++)
		a[i][n+i] = 1;
	for (int i = 1; i <= n; i++){
		if (a[i][i] == 0){
			for (int j = i+1; j <= n; j++)
				if (a[j][i] != 0){
					swap_rank(i, j);
					break;
				}
			if (!a[i][i]){
				cout << "No Solution" << '\n';
				return 0;
			}
		}
//		for (int j = n+1; j <= n*2; j++){
//			for (int k = 1; k <= n; k++)
//				cout << a[i][j] << ' ';
//			cout <<'\n';
//		}	
		mul_rank(i, inv(a[i][i]));
		for (int j = i+1; j <= n; j++)
			add_rank(i, j, mod - a[j][i]);
//		for (int j = n+1; j <= n*2; j++){
//			for (int k = 1; k <= n; k++)
//				cout << a[i][j] << ' ';
//			cout <<'\n';
//		}	
	}
	for (int i = n; i >= 1; i--){
		for (int j = i-1; j >= 1; j--)
			add_rank(i, j, mod - a[j][i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = n + 1; j <= 2 * n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}

