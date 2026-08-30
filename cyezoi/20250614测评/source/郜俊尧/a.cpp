#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
char ch[7][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int a[8], ans = -1, p;
	
	cin >> n;
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ch[i][j];
		}
	}
	
	for (int i = 1; i <= 5; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			if (ch[j][i] == 'Y') {
				cur++;
			}
		}
		a[i] = cur;
	}
	vector<int> v;
	int tmp = *max_element(a + 1, a + 6);
	for (int i = 1; i <= 5; i++) {
		if (a[i] == tmp) v.push_back(i);
	}
	
	for (int i = 0; i < v.size(); i++) {
		(i == v.size() - 1 ? cout << v[i] : cout << v[i] << ",");
	}
	
	
	return 0;

}

