#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int h, m, i, sh, sm;
} a[1005];
bool cmp(node x, node y){
	if (x.h != y.h) return x.h < y.h;
	if (x.m != y.m) return x.m < y.m;
	if (x.sh != y.sh) return x.sh < y.sh;
	if (x.sm != y.sm) return x.sm < y.sm;
	return x.i < y.i;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x1, y1, x2, y2;
		scanf("%d:%d", &x1, &y1);
		scanf("%d:%d", &x2, &y2);
		a[i].h = x1+x2;
		a[i].m = y1+y2;
		if (a[i].m >= 60){
			a[i].m -= 60;
			a[i].h++;
		}
		a[i].sh = x1;
		a[i].sm = y1;
		a[i].i = i;
	}
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++) cout << a[i].i << endl;
	return 0;
}