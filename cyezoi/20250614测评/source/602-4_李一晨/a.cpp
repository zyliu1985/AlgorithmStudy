#include<bits/stdc++.h>
const int N = 100005;
char a[N][5];
std::vector<int> ans;
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int n;std::cin >> n;
	for (int j = 1;j <= n;j++)
		for (int i = 0;i < 5;i++) 
			std::cin >> a[j][i];
	int mx = 0;
	for (int i = 0;i < 5;i++){
		int cnt = 0;
		for (int j = 1;j <= n;j++)
			if (a[j][i] == 'Y') ++cnt;
		if (cnt > mx) mx = cnt,ans.clear(),ans.push_back(i);
		else if (cnt == mx) ans.push_back(i);
	}
	for (int i = 0;i < ans.size() - 1;i++)
		std::cout << ans[i] + 1 << ',';
	std::cout << ans.back() + 1 << '\n';
	return 0;
}
