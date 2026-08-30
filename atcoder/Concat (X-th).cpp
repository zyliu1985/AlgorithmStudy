#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string s[15], t[100005];
int cur = 1, n, k;
void dfs(int x){
	if (x > k){
		cur++;
		return;
	}
	string now = t[cur];
	for (int i = 1; i <= n; i++){
		t[cur] = now;
		t[cur] += s[i];
		dfs(x+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	dfs(1);
//	for (int i = 1; i <= n; i++)
//		cout << t[i] << ' ';
	sort(t+1, t+cur);
	cout << t[x] << '\n';
	return 0;
}



