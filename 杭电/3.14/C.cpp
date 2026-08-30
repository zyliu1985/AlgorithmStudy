#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool box[1000005], flag[1000005];
int a[1000005], kind[1000005], from[1000005];
vector<int> zero;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		zero.clear();
		int n;
		cin >> n;
		for (int i = 1; i <= 1e6 + 1; i++){
			kind[i] = 0;
			from[i] = 0;
			box[i] = 0;
			flag[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n; i >= 1; i--){
			if (a[i] == 0){
				kind[i] = kind[i+1];
				continue;
			}
			kind[i] = kind[i+1] + (!box[a[i]]);
			box[a[i]] = 1;
		}
//		for (int i = 1; i <= n; i++){
//			cout << kind[i] << ' ';
//		} 
//		cout << '\n';
		long long ans = 0;
		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= 3; j++)
//				cout << from[j] <<' ';
//			cout << '\n';
//			for (int j = 0; j < zero.size(); j++)
//				cout << zero[j] << ' ';
//			cout << '\n';
			if (a[i] == 0){
				zero.push_back(i);
				continue;
			}
			if (from[a[i]] && !flag[a[i]]){
				int l = lower_bound(zero.begin(), zero.end(), from[a[i]]) - zero.begin();
				int r = lower_bound(zero.begin(), zero.end(), i) - zero.begin();
				if (l != r) ans += kind[i + 1], flag[a[i]] = true;
			}
			if (!from[a[i]]) from[a[i]] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}



