#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct node{
	int x, y;
} a[100005];
int xmin[200005], xmax[200005], ymin[200005], ymax[200005];
int main(){
	int n;
	cin >> n;
	memset(xmin, 0x3f, sizeof(xmin));
	memset(ymin, 0x3f, sizeof(ymin));
	for (int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
		a[i] = {a[i].x + 100000, a[i].y + 100000};
		xmin[a[i].y] = min(xmin[a[i].y], a[i].x);
		xmax[a[i].y] = max(xmax[a[i].y], a[i].x);
		ymin[a[i].x] = min(ymin[a[i].x], a[i].y);
		ymax[a[i].x] = max(ymax[a[i].x], a[i].y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, abs(xmax[a[i].y] - a[i].x) * abs(ymax[a[i].x] - a[i].y));
		ans = max(ans, abs(xmax[a[i].y] - a[i].x) * abs(ymin[a[i].x] - a[i].y));
		ans = max(ans, abs(xmin[a[i].y] - a[i].x) * abs(ymax[a[i].x] - a[i].y));
		ans = max(ans, abs(xmin[a[i].y] - a[i].x) * abs(ymin[a[i].x] - a[i].y));
	}
	cout << ans << endl;
	return 0;
}