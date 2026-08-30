#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1e5;
int root, tot = 1, cnt[N], sz[N], val[N], ch[N][2], f[N];
bool get(int x) {
    return ch[f[x]][1] == x;
}
void push_up(int x) {
    sz[x] = cnt[x] + sz[ch[x][0]] + sz[ch[x][1]];
}
void rotate(int x) {
    int y = f[x], z = f[y], k = get(x);
    if (z) ch[z][get(y)] = x;
    f[x] = z;
    ch[y][k] = ch[x][k^1];
    if (ch[x][k^1]) f[ch[x][k^1]] = y;
    ch[x][k^1] = y; f[y] = x;
    push_up(y), push_up(x);
}
void splay(int x, int goal = 0) {
    while (f[x] != goal) {
        int y = f[x], z = f[y];
        if (z != goal)
            rotate(get(x) == get(y) ? y : x);
        rotate(x);
    }
    if (!goal) root = x;
}
void find(int x) {
    int u = root;
    while (ch[u][x > val[u]] && x != val[u])
        u = ch[u][x > val[u]];
    splay(u);
}
void insert(int x) {
    int u = root, fa = 0;
    while (u && val[u] != x) {
        fa = u;
        u = ch[u][x > val[u]];
    }
    if (u) {
        cnt[u]++;
        push_up(u);
        push_up(fa);
    } else {
        u = tot++;
        val[u] = x;
        cnt[u] = 1;
        f[u] = fa;
        if (fa) ch[fa][x > val[fa]] = u;
        else root = u;
    }
    splay(u);
}
int pre(int x) {
    find(x);
    if (val[root] < x) return root;
    int u = ch[root][0];
    while (ch[u][1]) u = ch[u][1];
    return u;
}
int succ(int x) {
    find(x);
    if (val[root] > x) return root;
    int u = ch[root][1];
    while (ch[u][0]) u = ch[u][0];
    return u;
}
int quary_rank(int x) {
    find(x);
    if (val[root] < x) return sz[ch[root][0]] + cnt[root] + 1;
    else return sz[ch[root][0]] + 1;
}
int quary_kth(int k) {
    int u = root;
    while (true) {
        int left_sz = ch[u][0] ? sz[ch[u][0]] : 0;
        if (k <= left_sz) {
            u = ch[u][0];
        } else {
            k -= left_sz;
            if (k <= cnt[u]) return u;
            k -= cnt[u];
            u = ch[u][1];
        }
    }
}
void del(int x) {
    find(x);
    if (cnt[root] > 1) {
        cnt[root]--;
        push_up(root);
        return;
    }
    if (!ch[root][0] && !ch[root][1]) {
        root = 0;
        return;
    }
    if (!ch[root][0] || !ch[root][1]) {
        root = ch[root][0] ? ch[root][0] : ch[root][1];
        f[root] = 0;
        return;
    }
    int ort = root;
    int bigleft = pre(val[root]);
    splay(bigleft);
    ch[root][1] = ch[ort][1]; f[ch[ort][1]] = root;
    push_up(root);
}
stack<int> st;
int main() {
	int n, m;
	cin >> n >> m;
	insert(0), insert(n+1);
	for (int i = 1; i <= m; i++){
		char op;
		cin >> op;
		if (op == 'D'){
			int x;
			cin >> x;
			st.push(x);
			insert(x);
		} else if (op == 'Q'){
			int x;
			cin >> x;
			find(x);
			if (val[root] == x) cout << 0 << '\n';
			else cout << val[succ(x)] - val[pre(x)] - 1 << '\n';
		} else {
			del(st.top());
			st.pop();
		}
	}
    return 0;
}
