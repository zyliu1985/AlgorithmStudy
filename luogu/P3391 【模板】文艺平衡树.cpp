#include <iostream>
#include <algorithm>
using namespace std;

int cur, tr[100005], ch[100005][2], f[100005], sz[100005];
int fnd[100005], root = 1;
bool flag[100005];
bool get(int x){
	return (ch[f[x]][1] == x); 
}
void push_down(int x){
	if (flag[x]){
		swap(ch[x][0], ch[x][1]);
		flag[ch[x][0]] ^= 1;
		flag[ch[x][1]] ^= 1;
		flag[x] = 0;
	}
}
void push_up(int x){
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void rotate(int x){
	int y = f[x], z = f[y];
	push_down(y), push_down(x);
	bool k = get(x);
	if (ch[x][k^1])
		f[ch[x][k^1]] = y;
	ch[y][k] = ch[x][k^1];
	if (z)
		ch[z][get(y)] = x;
	f[x] = z;
	f[y] = x;
	ch[x][k^1] = y;
	push_up(y), push_up(x); 
}
void splay(int x, int goal = 0){
	while (f[x] != goal){
		int y = f[x], z = f[y];
		if (z != goal)
			rotate(get(x) == get(y) ? y : x);
		rotate(x);
	}
	if (!goal) root = x;
}
int build(int l, int r, int fa){
	if (l > r) return 0;
	int mid = (l + r) / 2;
	int x = ++cur;
	tr[x] = mid;
	fnd[mid] = x;
	f[x] = fa;
	if (l == r){
		sz[x] = 1;
		return x;
	}
	ch[x][0] = build(l, mid-1, x);
	ch[x][1] = build(mid+1, r, x);
	push_up(x);
	return x;
}
int n, m;
int rak(int rk){
	int now = root, addrk = 0;
	push_down(now);
	while (sz[ch[now][0]] + addrk + 1 != rk){
		int nowrk = sz[ch[now][0]] + addrk + 1;
		if (nowrk < rk && ch[now][1]){
			addrk += sz[ch[now][0]] + 1;
			now = ch[now][1];
		} else if (ch[now][0]) {
			now = ch[now][0];
		}
		push_down(now);
	}
	return now;
}
void reverse(int l, int r){
	int a = rak(l), b = rak(r+2);
	splay(a);
	splay(b, a);
	flag[ch[b][0]] ^= 1;
}
void print(int x){
	push_down(x);
	if (ch[x][0]) print(ch[x][0]);
	if (tr[x] != 0 && tr[x] != n+1) cout << tr[x] << ' ';
	if (ch[x][1]) print(ch[x][1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	build(0, n+1, 0);
	while (m--){
		int l, r;
		cin >> l >> r;
		reverse(l, r);
//		print(root);
//		cout << '\n';
//		for (int i = 0; i <= n+1; i++)
//			cout << i << ": " << (ch[fnd[i]][0] ? tr[ch[fnd[i]][0]] : -1) << ',' << (ch[fnd[i]][1] ? tr[ch[fnd[i]][1]] : -1) << '\n';
	}
	print(root);
	return 0;
}

