#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 15;
ll g, p, cnt = 0, flag;
bool v[maxn], s[maxn];

struct u{
	ll x, id;
}a[maxn];

bool cmp(u cmp1, u cmp2){return cmp1.x < cmp2.x;}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(v, 0, sizeof(v));
	memset(s, 0, sizeof(s));
	
	cin >> g;
	cin >> p;
	for (int i = 1; i <= p; i++){
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + p, cmp);
	for (int i = 1; i <= p; i++){
		flag = 0;
		for (int j = 1; j <= a[i].x; j++){
			if (!v[j]){
				v[j] = 1;
				flag = 1;
				break;
			}
		}
		if (flag == 0) s[a[i].id] = 1;
	}
	for (int i = 1; i <= p; i++){
		if (s[i] == 1){
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
