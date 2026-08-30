#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 15;
ll n, a[maxn], w[8], maxx = -1, k = 0;
char c[8];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c;
		for (int i = 0; i < 5; i++){
			if (c[i] == 'Y') w[i + 1]++;
		}
	}
	for (int i = 1; i <= 5; i++){
		maxx = max(maxx, w[i]);
	}
	k = 0;
	for (int i = 1; i <= 5; i++){
		if (w[i] == maxx){
			if (k == 0){
				cout << i;
				k++;
			}
			else cout << "," << i;
		}
	}
	return 0;
}
