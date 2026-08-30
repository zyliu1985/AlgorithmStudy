#include <bits/stdc++.h>
const int maxn = 2e3 + 5;
const int INF = 2e10;

int K, N, M, A, B;
std::pair<int, int> map[maxn][maxn];

int solve(int start, int time, int k){
	if(k >= K)
		return INF;
	if(start == B)
		return time;
	
	int ans;
	for(int i = 1; i <= N; ++i){
		if(map[start][i].first != 0 && map[start][i].second != 0)
			ans = std::min(ans, solve(i, time + map[start][i].first, k + map[start][i].second));
	}
}

int main() {
	std::cin >> K >> N >> M;
	for(int i = 1; i <= M; ++i) {
		int a, b, t, h;
		std::cin >> a >> b >> t >> h;
		if(h <= K)
			map[a][b] = map[b][a] = {t, h};
	}
	std::cin >> A >> B;

	std::cout << solve(A, 0, 0);
}
