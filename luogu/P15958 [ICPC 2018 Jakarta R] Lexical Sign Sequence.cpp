#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int n, k;
bool forced[100005];
int org[100005], lst[100005];
struct node{
	int a, b, c;
} s[100005];
bool cmp(node x, node y){
	return x.b < y.b;
}
int tr[100005], su[100005];
void init(){
	for (int i = 1; i <= n; i++)
		su[i] = su[i-1] + org[i];
	for (int i = 1; i <= n; i++)
		tr[i] = su[i] - su[i - lowbit(i)];
}
void add(int x, int w){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += w;
}
int find(int x){
	int re = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		re += tr[i];
	return re;
}
int query(int l, int r){
	return find(r) - find(l-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> org[i];
		if (org[i] == 0){
			org[i] = -1;
		} else {
			forced[i] = 1;
		}
		if (forced[i-1]) lst[i] = lst[i-1];
		else lst[i] = i-1;
	}
	for (int i = 1; i <= k; i++)
		cin >> s[i].a >> s[i].b >> s[i].c;
	sort(s+1, s+k+1, cmp);
	init();
	for (int i = 1; i <= k; i++){
		int sum = query(s[i].a, s[i].b);
		if (sum < s[i].c){
			int num = (s[i].c + 1 - sum) / 2;
			int now = s[i].b;
			while (num > 0){
				if (now < s[i].a){
					cout << "Impossible\n";
					return 0;
				}
				if (!forced[now]){
					add(now, 2);
					num--; 
					forced[now] = true;
				}
				now = lst[now];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << query(i, i) << ' ';
	return 0;
}
