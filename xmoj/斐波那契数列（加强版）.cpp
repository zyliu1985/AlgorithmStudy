#include <iostream>
#include <algorithm>
using namespace std;

int mod;
struct sq{
	int n, m;
	long long val[15][15];
	friend sq operator * (const sq a, const sq b){
		if (a.m != b.n) exit(21);
		sq c;
		c.n = a.n;
		c.m = b.m;
		for (int i = 1; i <= a.n; i++)
			for (int j = 1; j <= b.m; j++){
				c.val[i][j] = 0;
				for (int k = 1; k <= a.m; k++)
					c.val[i][j] = (c.val[i][j] + (a.val[i][k] * b.val[k][j]) % mod) % mod;
			}
		return c;
	}
	void print(){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	} 
};
sq qpow(sq x, int up){
	if (up == 1) return x;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
sq t, st; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	t.n = t.m = 2; 
	t.val[1][1] = 0;
	t.val[1][2] = t.val[2][1] = t.val[2][2] = 1;
	int n;
	cin >> n >> mod;
	if (n < 3){
		cout << 1 % mod << '\n';
		return 0;
	}
	if (n == 3){
		cout << 2 % mod << '\n';
		return 0;
	}
	st.n = 1, st.m = 2;
	st.val[1][1] = st.val[1][2] = 1;
	st = st * qpow(t, n - 3);
	cout << (st.val[1][1] + st.val[1][2]) % mod << '\n';
	return 0;
}

