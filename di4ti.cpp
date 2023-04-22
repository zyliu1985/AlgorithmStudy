#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int a[100005];

int main(){
	long long n, d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n-2; i++){
//		for (int j = i+2; j <= n; j++){
//			if (a[j]-a[i] > d){
//				break;
//			}
//			ans += j-i-1;
//		}
		int j = upper_bound(a+i, a+n+1, a[i]+d) - a;
		if (a[j] != a[i]+d){
			j--;
		}
//		cout << "j=" << j << "    count=" << j - i + 1;
		ans += (j-i) * (j-i -1) / 2;
//		cout << "   ans=" << ans << endl;
	}
	cout << ans << endl;
	return 0;
}