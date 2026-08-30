#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long seed;
int gen() {
	seed = seed ^ (seed << 13);
	seed = seed ^ (seed >> 7);
	seed = seed ^ (seed << 17);
	return (seed >> 33);
}
const int N = 1e8 + 1e7;
int a[200005], num[N + 5]; 
int main(){
	freopen("log.in", "r", stdin);
	freopen("log.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q >> seed;
	for (int i = 1; i <= 10000; i++)
		gen();
	for (int i = 1; i <= n; i++)
		a[i] = gen();
	sort(a+1, a+n+1);
	int cur = 1;
	for (int i = 1; i <= N; i++){
		while (cur <= n && a[cur] < i * 1ll * 20) cur++;
		num[i] = cur - 1;
	}
	long long ans = 0;
	for (int i = 1; i <= q; i++){
		int x = gen();
//		cout << x << ' ';
		int pt = x / 20;
		int now = num[pt];
//		cout << num[pt] << '\n';
		for (int i = num[pt] + 1; i <= num[pt+1]; i++)
			if (a[i] < x) now++;
			else break;
//		cout << now << "----\n";
		ans ^= now * 1ll * (i-1);
	}
	cout << ans << '\n';
	return 0;
}

