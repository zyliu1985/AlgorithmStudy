#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], b[200005];
long long s[200005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i], s[i] = s[i-1] + a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		int last = -1;
		long long ans = 0;
		for (int l = 1, r = 1; r <= n; r++){
			if (a[r] + b[r] != last)
				l = r, last = a[r] + b[r];
			ans = max(ans, (s[r] - s[l-1]) * (r - l + 1));
		}
		cout << ans << '\n'; 
	}
	return 0;
}



