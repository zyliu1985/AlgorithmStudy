#include <iostream>
#include <cmath>
using namespace std;

int a[100005];
int b[20], cnt;
bool vis[20];
inline int read(){
	int x = 0, f = 1;
	char c = getchar(); 
	while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();} 
	while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();} 
	return x*f;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
void chai(int x){
	int now = 2;
	while (x > 1){
		if (x % now == 0){
			b[++cnt] = now;
			while (x % now == 0) x /= now;
		}
		now++;
	}
}
int main(){
	freopen("unite.in", "r", stdin);
	freopen("unite.out", "w", stdout);
	int n = read(), gd;
	a[1] = read(), gd = a[1];
	for (int i = 2; i <= n; i++){
		a[i] = read();
		gd = gcd(gd, a[i]);
	}
	chai(gd);
	int ans = 0;
	for (int i = n; i >= 1; i--){
		bool flag = false;
		for (int j = 1; j <= cnt; j++)
			if (gcd(b[j], i) == 1 && !vis[j]){
				if (!flag) ans += n - i + 1;
				vis[j] = true;
				flag = true;
			}
	}
	cout << ans << endl;
}
