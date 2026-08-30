#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
long long frac[10005], finv[10005], pow2[10005];
struct node{
	int type, org;
} a[10005];
bool cmp(node x, node y){
	if (x.org / x.type != y.org / y.type) return x.org / x.type > y.org / y.type;
	return x.org > y.org;
}
int cur;
long long qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
long long inv(long long x){
	return qpow(x, mod-2);
}
long long C(int x, int y){
	if (x < y) return 0;
	if (x < 0 || y < 0) return 0;
	return frac[x] * finv[x-y] % mod * finv[y] % mod;
}
//int nxt2id(int x){
//	x++;
//	while (a[x].type == 1 && x <= cur) x++;
//	return x;
//}
int main(){
//	freopen("out.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	frac[0] = 1, finv[0] = 1, pow2[0] = 1;
	for (int i = 1; i <= 1e4; i++)
		frac[i] = frac[i-1] * i % mod, finv[i] = inv(frac[i]), pow2[i] = pow2[i-1] * 2 % mod;
	while (t--){
		cur = 1;
		a[1] = {1, 0};
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a[++cur].org = 2 * x, a[cur].type = 1;
			a[++cur].org = 2 * x, a[cur].type = 2;
		}
		sort(a+1, a+cur+1, cmp);
		cout << '\n';
		for (int i = 1; i <= cur; i++)
			cout << a[i].org << ' ' << a[i].type << '\n';
		cout << '\n';
		int num1 = 0, num2 = 0;
		long long ans = pow2[n];
		for (int i = 1; i <= cur; i++){
			if (a[i].type == 1){
				long long now = 0;
//				cout << "now num1: " << num1 << "   num2: " << num2 << '\n';
//				cout << num1 << ',' << num2 << '\n';
//				cout << num1 + num2 - 1 << ',' << num1 - 1 + num2 * 2 - (m-2) << '\n';
				long long mul = C(num1 + num2 - 1, num1 - 1 + num2 * 2 - (m-2));
//				cout << "mul = C(" << num1 + num2 - 1 << ", " << num1 - 1 + num2 * 2 - (m-2) << ") = " << mul << '\n';
				for (int j = i+1; j <= cur; j++)
					if (a[j].type == 2){
						
					}
				num1++;
				ans = (ans - now + mod) % mod;
			} else {
				num1--;
				num2++;
			}
		}
		cout << ans << '\n'; 
	}
	return 0;
}

