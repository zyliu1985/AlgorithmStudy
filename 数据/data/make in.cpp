#include <iostream>
#include <random>
#include <time.h>
using namespace std;

const int maxn = 100000;
const int maxm = 200000;
int f[100005], rd[100005], cd[100005], ch[100005];
bool flag[100005];
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
	cout.tie();
	mt19937 e{(unsigned int)time(NULL)};
//	for (int i = 1; i <= 100000; i++) f[i] = i;
	freopen("data1.in", "w", stdout);
//	int n = e() % maxn + 1;
//	int m = n - 1;
//	cout << n << ' ' << m << '\n';
//	for (int i = 1; i <= m;){
//		int u = e() % n + 1;
//		int v = e() % n + 1;
//		if (find(u) != find(v) && !(rd[u] == 0 && cd[u] > 0) && !flag[u]){
//			if (cd[u] > 0 && rd[v] > 0) continue;
//			rd[v]++;
//			cd[u]++;
//			if (cd[u] > 1){
//				flag[ch[u]] = true;
//				flag[v] = true;
//			}
//			ch[u] = v;
//			merge(u, v);
//			cout << u << ' ' << v << '\n';
//			i++;
//		}
//	}
	int n = 100000;
	int m = n - 1;
	cout << n << ' ' << m << endl;
 	int end = e() % n + 1;
 	flag[end] = true;
	for (int i = 1; i <= m;){
		int v = e() % n + 1;
		if (flag[v]) continue;
		cout << end << ' ' << v << endl;
		end = v;
		flag[v] = true;
		i++;
	}
	return 0;
}
