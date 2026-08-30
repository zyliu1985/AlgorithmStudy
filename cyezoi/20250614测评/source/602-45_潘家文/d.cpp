#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f, G = 1e5;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
int g, p, d[G + 5];

int lowbit(int x){ return x & -x; }

void us(int x){ for(; x <= g; x += lowbit(x)) -- d[x]; }

int get(int x){
	int res = 0;
	for(; x; x -= lowbit(x)) res += d[x];
	return res;
}

int main(){
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> g >> p;
	for(int i = 1; i <= g; ++ i) d[i] = lowbit(i);
	for(int i = 0; i < p; ++ i){
		cin >> t;
		if(!get(t)){
			cout << i;
			return 0;
		}
		int l = 1, r = t, o;
		while(l <= r){
			int mid = l + r >> 1;
			if(get(t) - get(mid - 1)){
				o = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		us(o);
	}
	cout << p;
}

