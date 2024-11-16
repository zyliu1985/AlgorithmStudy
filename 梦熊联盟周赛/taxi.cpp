#include <iostream>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int lft[200005], rgt[200005], x[200005], t[200005], id[200005], a[100005];
int main(){
	freopen("taxi.in", "r", stdin);
	freopen("taxi.out", "w", stdout);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	n += m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	int cur = 0;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		if (t[i] == 1)
			id[i] = ++cur;
	}
	// 构建lft 
	int lasttex = -1;
	for (int i = 1; i <= n; i++)
		if (t[i] == 0)
			lft[i] = lasttex;
		else
			lasttex = i;
	
	// 构建rgt
	lasttex = -1;
	 for (int i = n; i >= 1; i--)
		if (t[i] == 0)
			rgt[i] = lasttex;
		else
			lasttex = i;
	for (int i = 1; i <= n; i++)
		if (t[i] == 0)
			a[id[lft[i] == -1 ? rgt[i] : rgt[i] == -1 ? lft[i] : x[i] - x[lft[i]] > x[rgt[i]] - x[i] ? rgt[i] : lft[i]]]++;
	for (int i = 1; i <= n; i++)
		if (t[i] == 1)
			cout << a[id[i]] << ' ';
	return 0;
}
