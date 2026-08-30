#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int hurt[10005];
struct node{
	int a, h, id, num;
	friend bool operator < (const node x, const node y){
		if (x.num != hurt[x.id]) return true;
		if (y.num != hurt[y.id]) return false;
		if (x.h != y.h) return x.h > y.h;
		if (x.a != y.a) return x.a > y.a;
		return x.id > y.id;
	}
};
struct attk{
	int at, id;
} e[10005];
int ennum;
priority_queue<node> q;
bool cmp(attk x, attk y){
	return x.at > y.at;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		while (!q.empty()) q.pop();
		memset(hurt, 0, sizeof(hurt));
		int n, u, k, hq;
		ennum = n;
		cin >> n >> u >> k >> hq;
		for (int i = 1; i <= n; i++){
			int aa, hh;
			cin >> aa >> hh;
			q.push({aa, hh, i, 0});
			e[i] = {aa, i};
		}
		sort(e+1, e+n+1, cmp);
		while (ennum > 0 && hq > 0){
			
		}
	}
	return 0;
}



