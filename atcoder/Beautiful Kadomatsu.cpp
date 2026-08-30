#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int cur = 1;
int sz[300005];
bool fx[300005];
int sx[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, lst;
	cin >> n >> lst;
	if (n == 1){
		cout << 0 << '\n';
		return 0;
	}
	int x;
	cin >> x;
	if (x >= lst) fx[1] = 0;
	else fx[1] = 1;
	lst = x;
	sz[1] = 2;
	for (int i = 3; i <= n; i++){
		cin >> x;
		if ((x >= lst) ^ fx[cur]) sz[cur]++;
		else{
			cur++;
			fx[cur] = !fx[cur-1];
			sz[cur] = 1;
			if (fx[cur]) sz[cur-1]--;
			else sz[cur]++;
		}
		lst = x; 
	}
	for (int i = 1; i <= cur; i++)
		cout << fx[i] << ' ' << sz[i] << '\n'; 
	for (int i = cur; i >= 1; i--)
		if (fx[i] == 1) sx[i] = sx[i+1] + sz[i];
		else sx[i] = sx[i+1];
	long long ans = 0;
	for (int i = 1; i <= cur; i++)
		if (fx[i] == 0) ans = (ans + (sz[i] * 1ll * sx[i] % mod)) % mod;
	cout << ans << '\n';
	return 0;
}

