#include <iostream>
#include <cmath>
#include <vector> 
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
inline void write(int x, char end = '\n'){
	if (x < 0){
		putchar('-');
		write(-x, end);
		return;
	}
	int len = x ? 0 : 1, tx = x;
	while (x > 0){
		x /= 10;
		len++;
	}
	while (len--){
		putchar(tx / pow(10, len) + '0');
		tx %= int(pow(10, len));
	}
	putchar(end);
}
inline void endl(){
	putchar('\n');
}
vector<int> v[100005];
int cnt[100005];
bool ans[100005];
int main(){
	freopen("highway.in", "r", stdin);
	freopen("highway.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++){
		int a = read() + 1, b = read() + 1;
		v[a].push_back(i);
		v[b].push_back(i);
	}
	int i, num = 0;
	for (i = 1; i <= n && num < m; i++){
		ans[i] = true;
		for (int j = 0; j < v[i].size(); j++){
			if (cnt[v[i][j]] == 0) num++;
			cnt[v[i][j]]++;
		}
	}
	i--;
	for (int j = i; j >= 1; j--){
		bool flag = true;
		for (int k = 0; k < v[j].size(); k++)
			if (cnt[v[j][k]] == 1){
				flag = false;
				break;
			}
		if (flag){
			for (int k = 0; k < v[j].size(); k++)
				cnt[v[j][k]]--;
			ans[j] = false;
		}
	}
	for (int j = i; j >= 1; j--)
		cout << ans[j];
	endl();
	return 0;
}

