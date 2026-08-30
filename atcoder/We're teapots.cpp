#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int mod = 998244353;
int n, q;
int func[200005], a[200005];
int v[200005][2][2], lst[200005][2]; 
set<int> st;
int pre[200005];
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
int frac(int a, int b){
	return a * 1ll * qpow(b, mod - 2) % mod;
}
int C(int a, int b){
	return frac(frac(func[a], func[a - b]), func[b]);
}
int calc(int len, int num)[
	if (num > len / 2 + 1) return 0;
	return C(len - num + 1, num);
]
int calc(int len){
	return lst[len][0] + lst[len][1];
}
int value(int x){
	if (st.find(x) != st.end()){
		return (((v[x][0][0] + v[x][0][1]) % mod + v[x][1][0]) % mod + v[x][1][1]) % mod;
	}
	v[x][0][0] = 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	func[0] = 1;
	for (int i = 1; i <= n; i++)
		func[i] = func[i-1] * i % mod;
	lst[0][0] = 1;
	for (int i = 1; i <= n; i++){
		lst[i][0] = (lst[i-1][0] + lst[i-1][1]) % mod;
		lst[i][1] = lst[i-1][0];
	}
	st.insert(200001);
	pre[200001] = 0;
	long long ans = 0;
	while (q--){
		int x, y;
		cin >> x >> y;
		if (st.find(x) != st.end()){
			// ÐÞ¸Ä
			if (y == -1){
				// É¾³ý
				 
			} 
		}
	}
	return 0;
}

