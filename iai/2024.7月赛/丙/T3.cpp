#include <iostream>
#include <algorithm>
using namespace std;

int read(){
	int re = 0, type = 1;
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
struct node{
	int s, t;
} a[200005];
bool cmp(node x, node y){
	return x.t < y.t;
}
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i].s = read(), a[i].t = read();
	sort(a+1, a+n+1, cmp);
	int ans = 0, last = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].s >= last){
			ans++;
			last = a[i].t;
		}
	cout << ans << '\n';
	return 0;
}
