#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int f[20][1 << 20];
int a[20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, w;
	cin >> n >> w;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		cin >> a[i], f[1][1 << (i-1)] = a[i];
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < (1 << n); j++){
			if (f[i][j] == 0x3f3f3f3f) continue;
			for (int k = 1; k <= n; k++){
				if (!((j >> (k-1)) & 1)){
					if (f[i][j] + a[k] <= w) f[i][j | (1 << (k-1))] = min(f[i][j | (1 << (k-1))], f[i][j] + a[k]);
					f[i+1][j | (1 << (k-1))] = min(f[i+1][j | (1 << (k-1))], a[k]);
				}
			}
			if (j == (1 << n) - 1 && f[i][j] != 0x3f3f3f3f){
				cout << i << '\n';
				return 0;
			}
		}
	}
	return 0;
}
