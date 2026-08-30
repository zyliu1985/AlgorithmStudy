#include <bits/stdc++.h>
using namespace std;
int sum[6],n,maxn = -1;
vector<int> ans;
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		char c;
		for (int j = 1;j <= 5;j++){
			cin >> c;
			if (c == 'Y') sum[j]++;
		}
	}
	for (int i = 1;i <= 5;i++) maxn = max(maxn,sum[i]);
	for (int i = 1;i <= 5;i++) if (sum[i] == maxn) ans.push_back(i);
	for (int i = 0;i < ans.size();i++){
		cout << ans[i];
		if (i != ans.size() - 1) cout << ',';
	}
}
