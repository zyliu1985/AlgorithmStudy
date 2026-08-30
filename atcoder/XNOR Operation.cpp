#include <iostream>
#include <algorithm>
using namespace std;

bool a[200005], s[200005];;
int num[200005][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	s[0] = 1;
	num[0][1]++;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] ^ a[i] ^ 1;
		ans += num[i-1][s[i]];
		num[i][s[i]] = num[i-1][s[i]] + 1;
		num[i][s[i] ^ 1] = num[i-1][s[i] ^ 1];
	}
	cout << ans << '\n';
	return 0;
}

