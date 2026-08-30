#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int mod = 1 << 30;
int b[40000005];
long long s[40000005];
struct node{
	int id;
	long long val;
	__int128 dp;
};
deque<node> q;
void write(__int128 x){
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, type;
	cin >> n >> type;
	if (type == 0){
		for (int i = 1; i <= n; i++){
			int a;
			cin >> a;
			s[i] = s[i-1] + a;
		}
	} else {
		long long x, y, z, m;
		cin >> x >> y >> z >> b[1] >> b[2] >> m;
		for (int i = 3; i <= n; i++)
			b[i] = (x * b[i-1] % mod + y * b[i-2] % mod + z) % mod;
		int lst = 0;
		for (int i = 1; i <= m; i++){
			int p, l, r;
			cin >> p >> l >> r;
			for (int j = lst+1; j <= p; j++)
				s[j] = s[j-1] + (b[j] % (r - l + 1)) + l;
			lst = p;
		}
	}
	for (int i = 1; i <= n; i++){
		node now = {0, 0};
		while (!q.empty() && q.front().val <= s[i]){
			now = q.front();
			q.pop_front();
		}
		q.push_front(now);
		__int128 lst = s[i] - s[now.id];
		__int128 dp = now.dp + lst * lst;
//		if (dp[i] > 0){
//			write(dp[i]);
//			putchar('\n');
//		}
		node nxt = {i, lst + s[i], dp};
		while (!q.empty() && q.back().val >= nxt.val)
			q.pop_back();
		q.push_back(nxt);
//		for (int j = i-1; j >= 0; j--)
//			if (s[i] - s[j] >= lst[j]){
//				lst[i] = s[i] - s[j];
//				dp[i] = dp[j] + lst[i] * lst[i];
//				break;
//			}
	}
	write(q.back().dp);
	return 0;
}

