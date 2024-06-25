#include <iostream>
#include <algorithm>
using namespace std;

int f[1000005];
struct node{
	int x, y, c;
} c[2005];
bool cmp(node x, node y){
	return x.c < y.c;
}
int find(int x){
	if (f[x] == x) return x;
	int y = find(f[x]);
	f[x] = y;
	return y;
}
void merge(int x, int y){
	int zx = find(x);
	int zy = find(y);
	if (zx != zy)
		f[zx] = zy;
}
int main(){
	for (int i = 1; i <= 1000000; i++) f[i] = i;
	int n, cur = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			int x;
			cin >> x;
			c[++cur] = node{i, j, x};
		}
	sort(c+1, c+cur+1, cmp);
	int ans = 0;
	for (int i = 1, num = 0; i <= cur && num < n-1; i++){
		if (find(c[i].x) == find(c[i].y)) continue;
		num++;
		ans += c[i].c;
		merge(c[i].x, c[i].y);
	}
	cout << ans << endl;
	return 0;
}