#include <iostream>
#include <algorithm>
using namespace std;

long long b[100005];
long long add[100005];
bool f[100005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dolphin.in", "r", stdin);
    freopen("dolphin.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	f[1] = 1, add[1] = 0;
	for (int i = 1; i <= n; i++){
		if (i & 1){
			f[i+1] = f[i] ^ 1;
			add[i+1] = b[i] - add[i];
		} else {
			f[i+1] = f[i];
			add[i+1] = add[i] - b[i];
		}
		if (abs(add[i]) > 2e18){
			cout << -1 << '\n';
			return 0;
		}
	}
	long long minx = 1, maxx = 1e18;
	for (int i = 1; i <= n+1; i++){
		if (f[i]){
			minx = max(minx, -add[i]+1);
			maxx = min(maxx, 1000000000000000000 - add[i]);
		} else {
			if (add[i] < 0){
				cout << -1 << '\n';
				return 0;
			}
			minx = max(minx, add[i] - 1000000000000000000); 
			maxx = min(maxx, add[i] - 1);
		}
	}
	if (minx > maxx){
		cout << -1 << '\n';
		return 0;
	}
	cout << n+1 << '\n';
	for (int i = 1; i <= n+1; i++)
		cout << add[i] + minx * (f[i] ? 1 : -1) << '\n';
	return 0;
}



