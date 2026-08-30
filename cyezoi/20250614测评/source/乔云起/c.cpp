#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5050;
ll n, h[maxn];

ll check(ll x){
	ll sum = 0, ans = 2147483647;
	for (int i = 1; i <= n - x + 1; i++){
		sum = 0;
		for (int j = 1; j <= ceil(x * 1.0 / 2); j++){
			sum += abs(h[j + i - 1] - h[x + i - j]);
		}
		//cout << x << ' ' << sum << endl;
		ans = min(ans, sum);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++){
		cout << check(i) << ' ';
	}
	return 0;
}
