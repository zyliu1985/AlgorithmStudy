#include<bits/stdc++.h>
const int N = 5005;
int h[N];
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int n;std::cin >> n;
	for (int i = 1;i <= n;i++) std::cin >> h[i];
	for (int i = 1;i <= n;i++){
		int ans = INT_MAX;
		for (int l = 1;l + i - 1 <= n;l++){
			int r = l + i - 1,tmp = 0;
			for (int k = 0;k <= (r - l) / 2;k++) 
				tmp += std::abs(h[l + k] - h[r - k]);
			ans = std::min(ans,tmp);
		}
		std::cout << ans << ' ';
	}
	return 0;
}
