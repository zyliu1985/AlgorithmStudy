#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

int mod = 1e9 + 7;
struct sq{
	int n, m;
	long long val[100][100];
	void print(){
		cout << n << ' ' << m << ":\n";
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	} 
	friend sq operator * (const sq a, const sq b){
		if (a.m != b.n) exit(21);
		sq c;
		c.clear();
		c.n = a.n;
		c.m = b.m;
		for (int i = 1; i <= a.n; i++)
			for (int j = 1; j <= b.m; j++){
				for (int k = 1; k <= a.m; k++){
					c.val[i][j] = (c.val[i][j] + (a.val[i][k] * b.val[k][j]) % mod) % mod;
				}
			}
		return c;
	}
	void clear(){
		memset(val, 0, sizeof(val));
	}
};
sq qpow(sq x, int up){
//	cout << up << '\n'; 
//	x.print();
//	cout << '\n'; 
//	sq tt = x * x;
//	tt.print();
	if (up == 1) return x;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
sq t, st;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	t.n = t.m = n * 9;
	for (int i = 1; i <= m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		// a -> w * n + b
		t.val[a][(w-1)*n + b] = 1;
	}
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= n; j++)
			t.val[i*n + j][(i-1) * n + j] = 1;
	st.n = 1, st.m = n * 9;
	st.val[1][1] = 1;
	st = st * qpow(t, s);
	cout << st.val[1][n] << '\n'; 
	return 0;
}

