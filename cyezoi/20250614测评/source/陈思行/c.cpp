#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int minn = INT_MAX;
		if (i % 2 == 0){
			for (int j = i / 2; j <= n - i / 2; j++){
				int tot = 0;
				for (int k = 1; k <= i / 2; k++){
					tot += abs(a[j + k] - a[j - k + 1]);
				}
				minn = min(minn, tot);
			}
		}
		if (i % 2 == 1){
			for (int j = i / 2 + 1; j <= n - i / 2; j++){
				int tot = 0;
				for (int k = 1; k <= i / 2; k++){
					tot += abs(a[j + k] - a[j - k]);
				}
				minn = min(minn, tot);
			}
		}	
		cout << minn << " ";	
	}
	return 0;
}
