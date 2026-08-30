#include <iostream>
#include <algorithm>
using namespace std;

int hvch[500005], sz[500005];
int f[1500005]; 
int ch[500005][3], sum[500005], cur;
int nsum[500005], id[500005], lrt[500005];
bool lf[1000005];
int n;
bool init(int x){
	if (x > n) return lf[x - n];
	sz[x] = 1;
	for (int i = 0; i < 3; i++){
		sum[x] += init(ch[x][i]);
		if (ch[x][i] <= n){
			sz[x] += sz[ch[x][i]];
			if (sz[ch[x][i]] >= sz[hvch[x]])
				hvch[x] = ch[x][i];
		} else {
			hvch[x] = n+1;
		}
	}
	return (sum[x] >= 2);
}
void init2(int x, int rt){
	if (x > n) return;
	lrt[x] = rt;
	id[x] = ++cur;
	nsum[id[x]] = sum[x];
	init2(hvch[x], rt);
	for (int i = 0; i < 3; i++){
		if (ch[x][i] != hvch[x]){
			init2(ch[x][i], ch[x][i]);
		}
	}
}
//void push_up(int x){
//	tr1[x] = tr1[x*2] & tr1[x*2+1];
//	tr2[x] = tr2[x*2] & tr2[x*2+1];
//}
//void inittr(int x, int l, int r){
//	if (l == r){
//		tr1[x] = (nsum[l] == 1);
//		tr2[x] = (nsum[l] == 2);
//		return;
//	}
//	int mid = (l + r) / 2;
//	inittr(x*2, l, mid);
//	inittr(x*2+1, mid+1, r);
//	push_up(x);
//}
//bool query(int lt, int rt, int fd, int x = 1, int l = 1, int r = n){
//	if (r < lt || l > rt) return true;
//	if (fd == 1){
//		if (lt <= l && r <= rt) return tr1[x];
//	} else {
//		if (lt <= l && r <= rt) return tr2[x];
//	}
//	int mid = (l + r) / 2;
//	return query(lt, rt, fd, x*2, l, mid) & query(lt, rt, fd, x*2+1, mid+1, r);
//}
//void add(int lt, int rt, int tp, int x = 1, int l = 1, int r = n){
//	
//}
void solve1(int x){
	for (int i = id[x]; i >= id[lrt[x]]; i--)
		if (nsum[i] == 1){
			nsum[i]++;
		} else {
			nsum[i]++;
			return;
		}
	solve1(f[lrt[x]]);
}
void solve2(int x){
	for (int i = id[x]; i >= id[lrt[x]]; i--)
		if (nsum[i] == 2){
			nsum[i]--;
		} else {
			nsum[i]--;
			return;
		}
	solve2(f[lrt[x]]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> ch[i][0] >> ch[i][1] >> ch[i][2];
		f[ch[i][0]] = f[ch[i][1]] = f[ch[i][2]] = i;
	}
	for (int i = 1; i <= 2*n+1; i++){
		cin >> lf[i];
	}
	init(1);
	init2(1, 1);
	int q;
	cin >> q;
	while (q--){
		int x;
		cin >> x;
		lf[x-n] = !lf[x-n];
//		cout << lf[x-n] << '\n';
		if (lf[x-n]){
			solve1(f[x]);
		} else {
			solve2(f[x]);
		}
//		for (int i = 1; i <= n; i++)
//			cout << nsum[id[i]] << ' ';
//		cout << '\n';
		cout << (nsum[id[1]] >= 2) << '\n';
	} 
	return 0;
}

