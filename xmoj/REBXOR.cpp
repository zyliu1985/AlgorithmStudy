#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int xors[400005];
long long prmaxor[400005], edmaxor[400005];
int tr[12800005][2], cur;
bool ed[12800005];
void setup(){
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
long long calc(int x){
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		xors[i] = x ^ xors[i-1];
	}
	insert(0);
	for (int i = 1; i <= n; i++){
		insert(xors[i]);
		prmaxor[i] = max(prmaxor[i-1], calc(xors[i]));
	}
	setup();
	for (int i = n; i >= 1; i--){
		insert(xors[i]);
		edmaxor[i] = max(edmaxor[i+1], calc(xors[i]));
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, prmaxor[i] + edmaxor[i]);
	}
	cout << ans << '\n';
	return 0;
}

