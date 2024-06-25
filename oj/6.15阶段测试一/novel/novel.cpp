#include <iostream>
using namespace std;

int n, m;
int a[100005];
bool check(int mid){
	int day = 1, happy = 0;
	for (int i = 1; i <= m; i++){
		if (day > n) break;
		if (happy >= mid){
			day++;
			happy /= 2;
			i--;
			continue;
		}
		happy += a[i];
	}
	if (happy >= mid)
		day++;
	if (day > n) return true;
	else return false;
}
int main(){
//	freopen("novel.in","r",stdin);
//    freopen("novel.out","w",stdout);
	int l = 0, r = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
		r += a[i];
	}
	while (l < r){
		int mid = (l + r) / 2 + 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
