#include <iostream>
#include <algorithm>
using namespace std;

int f[40005];
struct edge{
	int x, y, w;
} e[100005];
bool cmp(edge x, edge y){
	return x.w > y.w;
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
	for (int i = 1; i <= 40000; i++) f[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].w;
	sort(e+1, e+m+1, cmp);
	for (int i = 1; i <= m; i++)
		if (find(e[i].x) != find(e[i].y)){
			merge(e[i].x, e[i].y+n);
			merge(e[i].x+n, e[i].y);
		} else {
			cout << e[i].w << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}