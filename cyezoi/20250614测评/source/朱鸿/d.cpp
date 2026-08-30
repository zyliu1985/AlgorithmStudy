#include <bits/stdc++.h>
using namespace std;

const int maxg = 1e5 + 5;

int g, p;

namespace sgt {
	int w[4 * maxg];
	
	inline void pushup(int u) {
		w[u] = w[u * 2] + w[u * 2 + 1];
	}
	
	void update(int u, int ul, int ur, int x, int k) {
		if (ul == x && ur == x) {
			w[u] += k;
		} else if (ul <= x && x <= ur) {
			int mid = (ul + ur) / 2;
			update(u * 2, ul, mid, x, k);
			update(u * 2 + 1, mid + 1, ur, x, k);
			pushup(u);
		}
	}
	
	int query(int u, int ul, int ur, int l, int r) {
		if (l <= ul && ur <= r) {
			return w[u];
		} else if (!(ur < l || ul > r)) {
			int mid = (ul + ur) / 2;
			return query(u * 2, ul, mid, max(l, ul), min(r, mid)) +
				query(u * 2 + 1, mid + 1, ur, max(l, mid + 1), min(r, ur));
		}
		return 0;
	}
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> g >> p;
	for (int i = 1; i <= p; i++) {
		int k;
		cin >> k;
		int tmp = sgt::query(1, 1, g, 1, k);
		if (tmp == k) {
			cout << i - 1 << "\n";
			return 0;
		}
		sgt::update(1, 1, g, k - tmp, 1);
	}
	cout << p << "\n";
	return 0;
}
