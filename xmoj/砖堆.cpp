#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int tr[1000005], n;
void add(int x, int val){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += val;
}
int quary(int x){
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr[i];
	return re;
}
void change(int l, int r){
	add(l, 1);
	add(r+1, -1);
}
int a[1000005];
int main(){
	freopen("brick.in", "r", stdin);
	freopen("brick.out", "w", stdout); 
	ios::sync_with_stdio(0);
    cin.tie(0);
	int k;
	cin >> n >> k;
	while (k--){
		int x, y;
		cin >> x >> y;
		change(x, y);
	}
	for (int i = 1; i <= n; i++)
		a[i] = quary(i);
	sort(a+1, a+n+1);
	cout << a[n / 2 + 1] << '\n'; 
	return 0;
}


