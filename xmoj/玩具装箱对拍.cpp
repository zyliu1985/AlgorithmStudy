#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int c[1005];
long long s[1005];
long long f[1005];
int main(){
//	freopen("in.in", "r", stdin);
//	freopen("force.out", "w", stdout); 
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> c[i], s[i] = s[i-1] + c[i]; 
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++){
			long long x = i - j - 1 + s[i] - s[j];
			f[i] = min(f[i], f[j] + (x - l) * (x - l));
		}
		cout << f[i] << '\n';
	}
	cout << f[n] << '\n';
	return 0;
}



