#include <iostream>
#include <algorithm>
using namespace std;

int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
struct node{
	int x, id;
} a[200005];
bool cmp(node x, node y){
	if (x.x != y.x) return x.x > y.x;
	return x.id < y.id;
}
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].id = i;
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i].id << '\n';
	return 0;
}
