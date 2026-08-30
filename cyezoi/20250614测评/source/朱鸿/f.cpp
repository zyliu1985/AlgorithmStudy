#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;
const int maxm = 105;

int n, m;
int a[maxn];
int b[maxm];

namespace sgt {
	int w[4 * maxn];
	
	inline void pushup(int u) {
		w[u] = max(w[u * 2], w[u * 2 + 1]);
	}
	
	void update(int u, int ul, int ur, int x, int k) {
		if (ul == x && ur == x) {
			w[u] = k;
		} else if (ul <= x && x <= ur) {
			int mid = (ul + ur) / 2;
			update(u * 2, ul, mid, x, k);
			update(u * 2 + 1, mid + 1, ur, x, k);
			pushup(u);
		}
	}
	
	int query(int u, int ul, int ur, int l, int r) {
		if (l > r) return 0;
		if (l <= ul && ur <= r) {
			return w[u];
		} else if (!(ur < l || ul > r)) {
			int mid = (ul + ur) / 2;
			return max(query(u * 2, ul, mid, max(l, ul), min(r, mid)),
				query(u * 2 + 1, mid + 1, ur, max(l, mid + 1), min(r, ur)));
		}
		return 0;
	}
	
	inline void init() {
		for (int i = 1; i <= 4 * (n + 1); i++) {
			w[i] = 0;
		}
	}
}
	
namespace t1 {
	int solve() {
		for (int i = 1; i <= n; i++) {
			sgt::update(1, 1, n, i, sgt::query(1, 1, n, 1, i - 2) + a[i]);
		}
		return sgt::query(1, 1, n, 1, n);
	}
}

namespace t2 {
	int a0[maxn];
	int solve() {
		int ans = 0;
		for (int i = 1; i <= n + 1; i++) {
			sgt::init();
			for (int j = 1; j <= i - 1; j++) {
				a0[j] = a[j];
			}
			for (int j = n; j >= i; j--) {
				a0[j + 1] = a[j];
			}
			a0[i] = b[1];
			for (int j = 1; j <= n + 1; j++) {
				sgt::update(1, 1, n + 1, j, sgt::query(1, 1, n + 1, 1, j - 2) + a0[j]);
			}
			ans = max(ans, sgt::query(1, 1, n + 1, 1, n + 1));
		}
		return ans;
	}
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	if (m == 0) cout << t1::solve() << "\n";
	else if (m == 1) cout << t2::solve() << "\n";	
	return 0;
}
