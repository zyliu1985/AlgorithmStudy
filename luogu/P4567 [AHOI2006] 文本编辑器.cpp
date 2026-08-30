#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2.1e5 + 5;
char val[N];
int ch[N][2], f[N], sz[N], root = 1;
int pos, cur;
bool flag[N];
bool get(int x){
	return (ch[f[x]][1] == x);
}
void push_up(int x){
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void push_down(int x){
	if (flag[x]){
		swap(ch[x][0], ch[x][1]);
		if (ch[x][0]) flag[ch[x][0]] ^= 1;
		if (ch[x][1]) flag[ch[x][1]] ^= 1;
		flag[x] = 0;
	}
}
void rotate(int x){
	int y = f[x], z = f[y];
	push_down(y), push_down(x);
	bool k = get(x);
	if (ch[x][k^1]) f[ch[x][k^1]] = y;
	ch[y][k] = ch[x][k^1];
	if (z) ch[z][get(y)] = x;
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
int rnk(int rk){
	int now = root;
	int addrk = 0;
	push_down(now);
	while (sz[ch[now][0]] + addrk + 1 != rk){
		int nowrk = sz[ch[now][0]] + addrk + 1;
		if (nowrk < rk){
			addrk += sz[ch[now][0]] + 1;
			now = ch[now][1];
		} else {
			now = ch[now][0];
		}
		push_down(now);
	}
	return now;
}
string s;
int build(int l, int r, int fa){
	if (l > r) return 0;
	int mid = (l + r) / 2;
	int x = ++cur;
	val[x] = s[mid];
	f[x] = fa;
	ch[x][0] = build(l, mid-1, x);
	ch[x][1] = build(mid+1, r, x);
	push_up(x);
	return x;
}
void insert(int l){
	int a = rnk(pos+1), b = rnk(pos+2);
	splay(a);
	splay(b, a);
	ch[b][0] = build(0, l-1, b);
}
void del(int l){
	int a = rnk(pos+1), b = rnk(pos+l+2);
	splay(a);
	splay(b, a);
	ch[b][0] = 0;
}
void reverse(int l){
	int a = rnk(pos+1), b = rnk(pos+l+2);
	splay(a);
	splay(b, a);
	flag[ch[b][0]] ^= 1;
}
char Get(){
	return val[rnk(pos+2)];
}
int read(){
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x;
}
void print(int x){
	push_down(x);
	if (ch[x][0]) print(ch[x][0]);
	cerr << val[x];
	if (ch[x][1]) print(ch[x][1]);
}
int main(){
	int n = read();
	cur = 2;
	ch[1][1] = 2;
	f[2] = 1;
	sz[2] = 1;
	sz[1] = 2;
	while (n--){
//		print(root);
//		cerr << pos << '\n';
		char c = getchar();
		while (c < 'A' || c > 'Z') c = getchar();
		if (c == 'M'){
			pos = read();
		} else if (c == 'I'){
			int x = read();
			s = "";
			for (int i = 1; i <= x; i++)
				s += getchar();
			insert(x);
		} else if (c == 'D'){
			int x = read();
			del(x);
		} else if (c == 'R'){
			int x = read();
			reverse(x);
		} else if (c == 'G'){
			putchar(Get());
			putchar('\n');
		} else if (c == 'P'){
			pos--;
		} else {
			pos++;
		}
	}
	return 0;
}

