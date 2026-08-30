#include<bits/stdc++.h>
const int C = 200005;
int a[C][2];
bool fin[C][2];
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int c;std::cin >> c;
	for (int j = 0;j < 2;j++)
		for (int i = 1;i <= c;i++)
			std::cin >> a[i][j];
	int ans = 0;
	for (int j = 0;j < 2;j++)
		for (int i = 1;i <= c;i++)
			if (a[i][j] == 1){
				int val = 3;
				if (fin[i - 1][j]) val -= 2;
				if (fin[i][!j] && i % 2 == 1) val -= 2;
				ans += val;
				fin[i][j] = 1;
			}
	std::cout << ans << '\n';
	return 0;
}
