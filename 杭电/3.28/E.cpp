#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10005], cnta;
int b[10005], cntb;
bool cmp(int x, int y){
	return x > y; 
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cnta = cntb = 0;
		int p, n, k;
		cin >> p >> n >> k;
		for (int i = 1; i <= n; i++){
			int t, x;
			cin >> t >> x;
			if (t == 0) a[++cnta] = x;
			else b[++cntb] = x;
		}
		sort(a+1, a+cnta+1);
		sort(b+1, b+cntb+1, cmp);
		double nowp = p;
		long long sumb = 0;
		for (int i = 1; i <= k; i++)
			sumb += b[i];
		int qwq = k; 
		a[0] = 10;
		double ans = 1e9;
		for (int i = 0; i <= min(cnta, k); i++){
			nowp *= a[i] * 0.1;
			ans = min(ans, max(nowp - sumb, 0.0));
			sumb -= b[qwq];
			qwq--;
		}
		printf("%.2f\n", ans);
	}
	
	return 0;
}



