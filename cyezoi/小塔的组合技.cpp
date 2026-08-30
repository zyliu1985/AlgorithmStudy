#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>
using namespace std;

mt19937 mt(1145141919);
long long num[100005], maxnum = 0;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int numb = 1e2;
		long long ANS = 0;
		int n, m, x = 1;
		cin >> n >> m;
		while (numb--){
			x = 1;
			memset(num, 0, sizeof(num));
			maxnum = 0;
			long long ans = 0;
			for (int i = 1; i <= m; i++){
				int target = mt() % n + 1;
//				cout << target << ' ';
				if (num[target] < maxnum) x++;
				else x = 1;
				num[target]++;
				maxnum = max(maxnum, num[target]);
				ans += (num[target] + 1) * x;
			}
//			if (ans > ANS) cout << "dkjaksldjaskd" << ans << '\n';
			ANS = max(ANS, ans);
		}
		cout << ANS << '\n';
	}
	return 0;
}



