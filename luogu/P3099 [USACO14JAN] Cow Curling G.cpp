#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int x, y;
} rpos[50005], bpos[50005];
bool cmp(node x, node y){
	return x.x < y.x;
}
deque<int> up[50005], dn[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> rpos[i].x >> rpos[i].y;
	for (int i = 1; i <= n; i++)
		cin >> bpos[i].x >> bpos[i].y;
	sort(rpos+1, rpos+n+1, cmp);
	sort(bpos+1, bpos+n+1, cmp);
	// solve red
	up[1] = 1;
	for (int i = 2; i <= )
	return 0;
}

