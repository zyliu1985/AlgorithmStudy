#include <iostream>
#include <algorithm>
using namespace std;

int dp[205][155], val[205];
int ch[205][205], idx, cnt[205];
void adp(int x, int num){
	if (dp[x][num]) return;
	dp[x][num] = val[x];
	if (num <= 0) return;
	for (int i = 0; i <= num; i++)
		
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	idx = n;
	for (int i = 1; i <= n; i++){
		int f;
		cin >> f >> val[i];
		if (cnt[f]) ch[ch[f][1]][++cnt[ch[f][1]]] = i;
		else ch[f][1] = i, cnt[f]++;
	}
	adp(0, m - 1);
	cout << dp[0][m] << '\n';
	return 0;
}



