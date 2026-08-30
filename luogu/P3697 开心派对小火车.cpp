#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int s[3005];
struct node{
	int fa, id, tm, ad;
	friend bool operator < (const node x, const node y){
		return x.ad < y.ad;
	}
};
priority_queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k, ans = -1;
	int a, b, c;
	long long t;
	cin >> n >> m >> k >> a >> b >> c >> t;
	k -= m;
	for (int i = 1; i <= m; i++)
		cin >> s[i];
	s[m+1] = n;
	for (int i = 1; i <= m; i++){
		if ((s[i] - 1) * b <= t){
			ans++;
			int lt = t - (s[i] - 1) * b;
			int nxt = min(n, s[i] + lt / a + 1);
			ans += lt / a;
			
			if (q.size() < k){
				q.push({i, nxt + 1, })
			}
		}
	}
	return 0;
}

