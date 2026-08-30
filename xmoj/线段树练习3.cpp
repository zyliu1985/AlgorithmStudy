#include <iostream>
#define lowbit(x) (x&-x) 
using namespace std;

int n, a[1000005], tr[1000005];
void build(){
	for (int i = 1; i <= n; i++)
		tr[i] = a[i] - a[i - lowbit(i)]; 
}
void change(int x, int val){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += val;
}
int quary(int l, int r){
	int suml = 0, sumr = 0;
	for (int i = l-1; i > 0; i -= lowbit(i))
		suml += tr[i];
	for (int i = r; i > 0; i -= lowbit(i))
		sumr += tr[i];
	return sumr - suml;
}
int main(){
	int q;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	cin >> q;
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int l, r, x;
			cin >> l >> r >> x;
			change(l, x);
			change(r+1, -x);
		} else {
			int x;
			cin >> x;
			cout << quary(1, x) << '\n';
		}
	}
	return 0;
}


