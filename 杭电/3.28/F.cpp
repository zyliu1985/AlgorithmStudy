#include <iostream>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int n;
long long a[200005], s[200005]; 
long long tr[200005];
void build(){
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] + a[i];
		tr[i] = s[i] - s[i - lowbit(i)];
	}
}
void change(int x, int u){
	long long add = u - a[x];
	a[x] = u;
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += add;
}
long long quary(int x){
	long long re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr[i];
	return re;
}
long long ans = 0;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		ans = 0;
		memset(tr, 0, sizeof(tr)); 
		memset(a, 0, sizeof(a)); 
		memset(s, 0, sizeof(s)); 
		int cnt = 0;
		int q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		build();
		while (q--){
			int op, x, y;
			cin >> op >> x >> y;
			if (op == 1) change(x, y);
			else{
				ans ^= ((quary(y) / 100) - (quary(x-1) / 100)) * (++cnt);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}



