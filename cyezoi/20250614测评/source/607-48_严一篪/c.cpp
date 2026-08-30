#include <bits/stdc++.h>
const int maxn = 5e3 + 5;
const long long INF = 1e15 + 5;

int mount[maxn];
long long ans[maxn][maxn];
long long dist[maxn][maxn];

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("ans.out", "w+", stdout);

	int n;
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		std::cin >> mount[i];
			
	}
	
	for(int i = 1; i <= n; ++i){
		dist[1][i] = 0;
		if(i != n)
			dist[2][i] = std::abs(mount[i] - mount[i + 1]);
		for(int j = 1; j <= std::min(i - 1, n - i); ++j){
			dist[1 + j * 2][i] = dist[1 + (j - 1) * 2][i] + std::abs(mount[i - j] - mount[i + j]);
			if(i + 1 + j <= n)
				dist[2 + j * 2][i] = dist[2 + (j - 1) * 2][i] + std::abs(mount[i - j] - mount[i + 1 + j]);
		}
	}

	for(int i = 1; i <= n; ++i){
		long long out = INF;
		for(int j = 1 + (i - 1) / 2; j <= n - i / 2; ++j){
			out = std::min(out, dist[i][j]);
			if(out == 0){
				break;
			}
		}
		std::cout << out << " ";
	}
}
