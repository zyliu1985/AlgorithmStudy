#include <iostream>
using namespace std;

const int mod = 998244353;
int f[2005][2005], a[2005], s[2005], g[2005][2005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	for (int i = 1; i <= n; i++) f[i][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j < i; j++){
			f[i][j] = g[j - 1][s[i] % j];
			
		}
	return 0;
}