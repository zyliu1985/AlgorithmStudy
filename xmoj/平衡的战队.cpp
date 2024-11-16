#include <iostream>
#include <algorithm>
using namespace std;

int s[50005], t[100005], last[50005], dp[50005];
struct node{
	int b, d;
} a[50005];
bool cmp(node x, node y){
	return x.d < y.d;
}
int main(){
	int n;
	cin >> n;
	s[0] = 50000;
	for (int i = 1; i <= n; i++){
		cin >> a[i].b >> a[i].d;
		a[i].b = a[i].b * 2 - 1;
	}
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i].b;
	// ÉèÖÃ t 
	for (int i = 1; i <= n; i++){
		if (t[s[i]] != 0)
			last[i] = t[s[i]];
		else
			last[i] = i;
		t[s[i]] = i;
	}
	// ³õÊ¼»¯ dp
	for (int i = 1; i <= n; i++)
		dp[i] = i;
	a[n+1].d = 1e9;
	// dp
	for (int i = 1; i <= n; i++)
		dp[i] = dp[last[i]];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, a[i].d - a[dp[i] + 1].d);
	cout << ans << endl;
	return 0;
}
