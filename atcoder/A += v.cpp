#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int num, val;
} box[500005];
long long ct[500005];
struct qes{
	int id;
	long long val;	
} qs[500005];
bool cmp(node x, node y){
	if (x.num != y.num) return x.num < y.num;
	else return x.val < y.val;
}
bool cmp1(qes x, qes y){
	return x.val < y.val;
}
bool cmp2(qes x, qes y){
	return x.id < y.id;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		box[x].num++;
	}
	for (int i = 1; i <= m; i++)
		box[i].val = i;
	sort(box+1, box+m+1, cmp);
	ct[1] = n;
	for (int i = 2; i <= m; i++)
		ct[i] = ct[i-1] + 1ll * (i-1) * (box[i].num - box[i-1].num);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> qs[i].val, qs[i].id = i;
	sort(qs+1, qs+q+1, cmp1);
	
	return 0;
}

