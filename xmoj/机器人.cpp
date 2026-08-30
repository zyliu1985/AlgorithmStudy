#include <iostream>
#include <algorithm>
using namespace std;

int c[100005], k[100005];
struct node{
	int p, q;
} x[100005];
bool cmp(node a, node b){
	return a.q > b.q;
}
bool cnp(int a, int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> x[i].p >> x[i].q;
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	sort(c+1, c+n+1, cnp);
	sort(x+1, x+n+1, cmp);
	sort(k+1, k+n+1, cnp);
	int r = n;
	for (int i = 1; i <= r; i++){
		
	}
	return 0;
}

