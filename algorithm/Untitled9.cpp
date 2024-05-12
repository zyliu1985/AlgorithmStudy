#include <iostream>
using namespace std;

int f[800005], size[800005], ans[800005];
bool flag[800005];
struct ques{
	char c;
	int num;
} qu[800005];
struct node{
	int x, y, w;
} e[800005];
int find(int x){
	if (f[x] == x) return x;
	int y = find(f[x]);
	f[x] = y;
	return y;
}
void merge(int x, int y){
	int zx = find(x);
	int zy = find(y);
	if (zx != zy){
		f[zx] = zy;
		size[zy] = max(size[zy], size[zx]);
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> size[i];
	for (int i = 1; i < n; i++)
		cin >> e[i].x >> e[i].y;
	int q, cur = 0;
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> qu[i].c >> qu[i].num;
		if (qu[i].c == 'D') flag[qu[i].num] = true;
		else cur++;
	}
	int t = cur;
	for (int i = 1; i < n; i++)
		if (!flag[i])
			merge(e[i].x, e[i].y);
	for (int i = q; i >= 1; i--)
		if (qu[i].c == 'Q') ans[cur--] = size[find(qu[i].num)];
		else merge(e[qu[i].num].x, e[qu[i].num].y);
	for (int i = 1; i <= t; i++)
		cout << ans[i] << endl;
	return 0;
}