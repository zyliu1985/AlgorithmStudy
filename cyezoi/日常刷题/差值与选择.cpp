#include <iostream>
#include <algorithm>
using namespace std;

int a[10005], b[10005];
int main(){
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> k;
// 55·Ö
//	int l = a[1] - k, g = a[1] - k;
//	for (int i = 2; i <= n; i++){
//		int b1 = a[i] - k;
//		int b2 = a[i] + k;
//		int ans;	
//		if (l - b1 < b2 - g)
//			ans = b1;
//		else
//			ans = b2;
//		l = min(ans, l);
//		g = max(ans, g);					
//	}
//	l = a[1] + k, g = a[1] + k;
//	for (int i = 2; i <= n; i++){
//		int b1 = a[i] - k;
//		int b2 = a[i] + k;
//		int ans;		
//		if (l - b1 < b2 - g)
//			ans = b1;
//		else
//			ans = b2;
//		l = min(ans, l);
//		g = max(ans, g);					
//	}
//	cout << g - l << endl;

// 70·Ö
//	int sum;
//	for (int i = 1; i <= n; i++)
//		sum += a[i];
//	double p = sum * 1.0 / n;
//	sort(a+1, a+n+1);
//	for (int i = 1; i <= n; i++)
//		if (a[i] <= p) b[i] = a[i] + k;
//		else b[i] = a[i] - k;
//	int maxn = -1e9, minn = 1e9;
//	for (int i = 1; i <= n; i++){
//		maxn = max(maxn, b[i]);
//		minn = min(minn, b[i]);
//	}
//	cout << min(maxn-minn, a[n]-a[1]) << endl;
	sort(a+1, a+n+1);
	int ans = 1e9;
	for (int i = 0; i <= n; i++){
		int maxn = -1e9, minn = 1e9;
		for (int j = 1; j <= n; j++){
			if (j <= i){
				maxn = max(maxn, a[j]+k);
				minn = min(minn, a[j]+k);
			} else {
				maxn = max(maxn, a[j]-k);
				minn = min(minn, a[j]-k);
			}
		}
//		cout << maxn << ' ' << minn << endl;
		ans = min(ans, maxn-minn);
	}
	cout << ans << endl;
	// 1 2 2 6 9
	// k = 5
	// 6 7 7 1 4
}