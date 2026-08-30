#include<bits/stdc++.h>
const int N = 1e5 + 5;
int g[N];bool f[N];
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int G,p;std::cin >> G >> p;
	for (int i = 1;i <= p;i++) std::cin >> g[i];
	int ans = 0;
	for (int i = 1;i <= p;i++){
		int tmp = g[i];
		while (tmp >= 1 && f[tmp]) --tmp;
		if (tmp == 0) break;
		else f[tmp] = 1,++ans;
	}
	std::cout << ans << '\n';
	return 0;
}
