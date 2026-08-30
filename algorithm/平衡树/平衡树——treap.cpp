#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

const int N = 1e5;
int v[N]
int root, tot = 1, val[N], wei[N], ch[N][2], cnt[N], sz[N];
void push_up(int x){
	sz[x] = cnt[x] + sz[ch[x][0]] + sz[ch[x][1]];
}
void lturn(int &x){
	int t = ch[x][1];
	ch[x][1] = ch[t][0];
	ch[t][0] = x;
	sz[t] = sz[x];
	push_up(x);
	x = t;
}
void rturn(int &x){
	int t = ch[x][0];
	ch[x][0] = ch[t][1];
	ch[t][1] = x;
	sz[t] = sz[x];
	push_up(x);
	x = t;
}
int build(int _v){
	val[tot] = _v; wei[tot] = rand(); cnt[tot] = 1; ch[tot][0] = ch[tot][1] = 0;
	tot++;
	return tot-1;
}
int insert(int &rt, int x){
	if (rt == 0) return;
	if (val[rt] == x){
		cnt[rt]++;
		return;
	} else if (val[rt] < x){
		int u;
		if (ch[rt][1]){
			u = insert(ch[rt][1], x);
		}
		if (wei[val[rt]] > wei[x]) lturn(rt);
	} else if (val[rt] > x){
		insert(ch[rt][0], x);
		if (wei[val[rt]] > wei[x]) rturn(rt);
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	return 0;
}



