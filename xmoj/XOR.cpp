#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100005];
int tr[3200005][2], cur;
bool ed[3200005];
void set_up(){
	cur = 0;
	memset(tr, 0, sizeof(tr));
	memset(ed, false, sizeof(ed));
}
void insert(int x){
	int now = 0;
	for (int i = 31; i >= 0; i--){
		bool c = (x >> i) & 1;
		if (!tr[now][c]){
			cur++;
			tr[now][c] = cur;
			now = cur;
		} else {
			now = tr[now][c];
		}
	}
	ed[now] = true;
}
int calc(int x){
	int now = 0, re = 0;
	for (int i = 31; i >= 0; i--){
		bool c = (x >> i) & 1;
		if (tr[now][!c]){
			now = tr[now][!c];
			re += (1 << i);
		} else {
			now = tr[now][c];
		}
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], insert(a[i]);
	for (int i = 1; i <= n; i++)
		ans = max(ans, calc(a[i]));
	cout << ans << '\n';
	return 0;
}

