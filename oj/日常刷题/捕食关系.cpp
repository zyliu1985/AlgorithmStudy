#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int type, val;
} ag[200005];
bool cmp(node x, node y){
	if (x.val != y.val) return x.val > y.val;
	return x.type > y.type;
}
long long ans;
int main(){
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ag[++cnt] = {0, x};
	}
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		ag[++cnt] = {1, x};
	}
	sort(ag+1, ag+cnt+1, cmp);
	int cur = 0;
	for (int i = 1; i <= cnt; i++)
		if (ag[i].type == 0) cur++;
		else ans += cur;
	cout << ans << endl;
	return 0;
}