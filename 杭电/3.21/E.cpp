#include <iostream>
#include <algorithm>
using namespace std;

int f[300005], c;
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		c--;
		f[zx] = zy;
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		c = n;
		for (int i = 1; i <= n; i++)
			f[i] = i;
		for (int i = 1; i <= n; i++){
			int a;
			cin >> a;
			if (i - a >= 1) merge(i, i-a);
			if (i + a <= n) merge(i, i+a);
		}
		cout << c - 1 << '\n';
	}
	return 0;
}



