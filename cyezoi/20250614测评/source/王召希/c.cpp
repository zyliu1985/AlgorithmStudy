#include <bits/stdc++.h>
using namespace std;
int n, a[5010], ans = 1e9, sum;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){ // ³¤¶ÈÎªi 
		ans = 1e9;
		for (int j = 1; j + i - 1 <= n; j++){
			sum = 0;
			for (int k = 0; k <= (i - 1) / 2; k++)
				sum += abs(a[j + k] - a[j + i - 1 - k]);
//			printf("%d %d %d\n", i, j, sum);
			ans = min(ans, sum);
		}
		cout << ans << " ";
	}
	return 0;
}
