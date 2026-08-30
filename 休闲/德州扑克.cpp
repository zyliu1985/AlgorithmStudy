#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	long long a, b;
	int id;
} v[1000005];
bool cmp(node x, node y){
	if (x.a != y.a) return x.a < y.a;
	return x.b > y.b;
}
double ans[1000005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].a;
	for (int i = 1; i <= n; i++)
		cin >> v[i].b, v[i].id = i;
	sort(v+1, v+n+1, cmp);
	int minus = 0;
	for (int i = 1; i <= n; i++)
		
	return 0;
}



