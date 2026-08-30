#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	long long a, b;
} x[200005];
bool cmp(node p, node q){
	return p.a - p.b < q.a - q.b;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	long long n;
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> x[i].a >> x[i].b;
	sort(x+1, x+m+1, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		if (n >= x[i].a) ans += (n - x[i].b) / (x[i].a - x[i].b), n -= (n - x[i].b) / (x[i].a - x[i].b) * (x[i].a - x[i].b);
	}
	cout << ans << '\n';
	return 0;
}



