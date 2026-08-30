#include <iostream>
using namespace std;

int a[1000005], ans[1000005], cur;
int mxps[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
//	freopen("sequence.in", "r", stdin);
//	freopen("sequence.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		cur = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
//		cout << "----------\n";
		a[0] = 0;
		mxps[n+1] = 0;
		for (int i = n; i >= 1; i--){
			mxps[i] = mxps[i+1];
			if (a[i] >= a[mxps[i]])
				mxps[i] = i;
		}
		int now = 0;
		while (now < n){
			now = mxps[now+1];
			ans[++cur] = a[now];
			a[now] = -1;
		}
		int maxn = 0, lst = 1;
		bool flag = true;
		now = 1;
		for (int i = 1; i <= n; i++){
			if (a[i] == -1){
				cout << ans[now] << ' ';
				if (flag && maxn >= ans[now+1]){
					mxps[i] = 0;
					for (int j = i-1; j >= lst; j--){
						mxps[j] = mxps[j+1];
						if (a[j] >= a[mxps[j]])
							mxps[j] = j;
					}
					int now2 = lst-1;
					while (now2 < i-1 && a[mxps[now2+1]] >= ans[now+1]){
						now2 = mxps[now2+1];
						cout << a[now2] << ' ';
					}
					flag = false;
				}
				now++;
				lst = i+1;
				maxn = 0;
			} else {
				maxn = max(maxn, a[i]);
			}
		}
		cout << '\n';
	}
	return 0;
}
