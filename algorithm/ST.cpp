#include <iostream>
using namespace std;

class ST{
	int val[500005][25], Log2[500005], len;
	bool is_max;
	int cmp(int x, int y){
		if (is_max){
			if (x > y) return x;
			else return y;
		} else {
			if (x < y) return x;
			else return y;
		}
	}
	
	public:
	
	ST(int x, bool y){
		Log2[0] = -1;
		for (int i = 1; i <= x; i++)
			Log2[i] = Log2[i / 2] + 1;
		len = x;
		is_max = y;
	}
	void init(int* a){
		for (int j = 1; j <= len; j++)
			val[j][0] = a[j];
		for (int i = 1; i <= Log2[len]; i++)
			for (int j = 1; j <= len - (1 << i) + 1; j++)
				val[j][i] = cmp(val[j][i-1], val[j + (1 << (i - 1))][i-1]);
	}
	int quary(int l, int r){
		if (l < 1 || r > len) return -1;
		int k = Log2[r - l + 1];
		return cmp(val[l][k], val[r - k + 1][k]);
	}
};
int a[100005];
int main(){
	int n;
	cin >> n;
	ST st(n, true);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	st.init(a);
//	int q;
//	cin >> q;
//	for (int i = 1; i <= q; i++){
//		int l, r;
//		cin >> l >> r;
//		cout << st.quary(l, r) << endl;
//	}
	return 0;
}
