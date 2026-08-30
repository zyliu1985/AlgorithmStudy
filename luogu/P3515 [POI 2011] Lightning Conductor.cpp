#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int h[500005];
double ans[500005], temp[500005];
void solve(int cl, int cr, int lql, int lqr, int rql, int rqr){
	if (cl > cr) return;
	int mid = (cl + cr) / 2;
	int lnowq, rnowq;
	for (int i = lql; i <= min(mid, lqr); i++)
		if (h[i] + sqrt(abs(mid - i)) > ans[mid]){
			ans[mid] = h[i] + sqrt(abs(mid - i));
			lnowq = i;
		}
	for (int i = max(rql, mid); i <= rqr; i++)
		if (h[i] + sqrt(abs(mid - i)) > temp[mid]){
			temp[mid] = h[i] + sqrt(abs(mid - i));
			rnowq = i;
		}
	ans[mid] = max(ans[mid], temp[mid]);
	solve(cl, mid-1, lql, lnowq, rql, rnowq);
	solve(mid+1, cr, lnowq, lqr, rnowq, rqr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	solve(1, n, 1, n, 1, n);
//	for (int i = 1; i <= n; i++)
//		cout << ans[i] << ' ';
//	cout << '\n';
	for (int i = 1; i <= n; i++)
		cout << int(ans[i] + 0.9999) - h[i] << '\n';
	return 0;
}

