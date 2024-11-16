#include <iostream>
#include <algorithm>
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
long long a[100005], s[100005], pows[100005];
int main(){
	freopen("assess.in", "r", stdin);
	freopen("assess.out", "w", stdout); 
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] + a[i];
		pows[i] = pows[i-1] + a[i] * a[i];
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		ans += (i - 1) * a[i] * a[i] - 2 * a[i] * s[i-1] + pows[i-1];
	cout << ans << endl;
	return 0;
}
