#include <iostream>
#include <algorithm>
using namespace std;

int d[10000005], p[10000005], cur; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n, l;
	cin >> n >> l;
	for (int i = 2; i <= l / (n-1); i++){
		if (!d[i]) p[++cur] = i, d[i] = i;
		for (int j = 1; p[j-1] != d[i]; j++){
			if (i * p[j] <= l / (n-1)) d[i * p[j]] = d[i];
			else break;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= cur; i++)
		ans += l - p[i] * (n-1) + 1;
	cout << ans << '\n'; 
	return 0;
}



