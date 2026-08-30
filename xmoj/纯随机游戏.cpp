#include <iostream>
#include <algorithm>
using namespace std;

bool box[1000005];
int a[500005], b[500005], cur = 0;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i], box[a[i]] = 1;
	for (int i = 1; i <= 2 * n; i++)
		if (!box[i]) b[++cur] = i;
	sort(a+1, a+n+1);
	int x1, y1, nx, ny;
	x1 = n, y1 = 1, nx = ny = 1;
	while (ny <= n){
		if (b[ny] > a[nx]) nx++, ny++;
		else x1--, y1++, ny++;
	}
	
	return 0;
}



