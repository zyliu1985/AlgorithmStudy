//鬼知道我能拿多少分 

#include <bits/stdc++.h>

using namespace std;

struct node {
	int b, t, h;
};

int k, n, m, t[2010], h[2010];
vector<node> G[2010];
bool vis[2010];

void bfs(int A, int B) {
	queue<int> Q;
	Q.push(A);
	t[A] = h[A] = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		if (now == B) return;
		for (node nxt : G[now]) {
			if (vis[nxt.b]) continue;
			t[nxt.b] = t[now] + nxt.t;
			h[nxt.b] = h[now] + nxt.h;
			vis[nxt.b] = true;
		}
	}
}

int main() {
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++) {
		int A, B, T, H;
		cin >> A >> B >> T >> H;
		G[A].push_back({B, T, H});
		G[B].push_back({A, T, H});
	}
	int A, B;
	cin >> A >> B;
	bfs(A, B);
	if (h[B] < k) cout << t[B] << "\n";
	else cout << "-1\n";
	return 0;
}
