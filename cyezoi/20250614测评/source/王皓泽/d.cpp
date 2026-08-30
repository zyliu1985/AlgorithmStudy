//O(n^2) with optimization
#pragma GCC target("avx")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-Ofast")
#include<bits/stdc++.h>
using namespace std;
bool park[200010];
int n;
int main() {
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int prk;
		cin >> prk;
		int num = prk - 1;
		while(park[num]) {
			if(num == 0) {
				cout << i;
				return 0;
			} else {
				num--;
			}
		}
		park[num] = 1;
	}
	cout << n;
	return 0;
}
/*
4 3
4 1 1
1 2 3 4

1: nullptr
2: 1
3: 2, 4
4: nullptr

input 4:
3 -> 4 : ok

*/
