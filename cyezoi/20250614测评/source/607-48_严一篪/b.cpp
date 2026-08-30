#include <bits/stdc++.h>
int brick[2][200005];

int main() {
	int c;
	std::cin >> c;

	long long ans = 0;
	for(int i = 1; i <= 2; ++i)
		for(int j = 1; j <= c; ++j) {
			std::cin >> brick[i][j];
			if(brick[i][j] == 1) {
				ans += 3;
				if(brick[i - 1][j] == 1 || brick[i][j - 1] == 1)
					ans -= 2;
			}
		}
	
	std::cout << ans;
}
