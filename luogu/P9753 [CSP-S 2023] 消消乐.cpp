#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;
long long f[2000005], g[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	s = ' ' + s;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		g[i] = i-1;
		while (g[i] > 0 && (s[i] != s[g[i]])) g[i] = g[g[i]]-1;
		if (g[i] > 0) f[i] = f[g[i]-1] + 1;
		ans += f[i];
	}
	cout << ans << '\n';
	return 0;
}

