#include <iostream>
#include <algorithm>
using namespace std;

int D;
long long l[800005], r[800005], val[800005];
void push_up(int x){
	val[x] = max(val[x * 2], val[x * 2 + 1]);
}
void build(int x = 1, int lt = 1, int rt = 800000){
	l[x] = lt, r[x] = rt;
	if (lt != rt){
		build(x * 2, lt, (lt + rt) / 2);
		build(x * 2 + 1, (lt + rt) / 2 + 1, rt);
	}
}
void add_one(int ps, int u, int x = 1){
	if (l[x] == r[x]){
		val[x] = (val[x] + u) % D;
		return;
	}
	if (ps <= (l[x] + r[x]) / 2){
		add_one(ps, u, x * 2);
	} else {
		add_one(ps, u, x * 2 + 1);
	}
	push_up(x);
}
int quary(int lt, int rt, int x = 1){
	if (r[x] < lt || rt < l[x]) return 0;
	if (lt <= l[x] && r[x] <= rt) return val[x];
	return max(quary(lt, rt, x * 2), quary(lt, rt, x * 2 + 1));
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	build();
	cout << "-------------\n";
	int m, lst = 0, l = 0;
	cin >> m >> D;
	while (m--){
		char op;
		cin >> op;
		if (op == 'Q'){
			int x;
			cin >> x;
			lst = quary(l - x + 1, l);
			cout << lst << '\n';
		} else {
			int x;
			cin >> x;
			l++;
			add_one(l, x + lst);
		}
	}
	return 0;
}

