#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int a[N];
bool vis[N];
int vis2[N];
int n, pl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> pl;

	for (int i = 1; i <= pl; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= pl; i++) {
//		if (vis2[a[i]]) {
//			if (vis2[a[i]] < a[i] && !vis[a[i] - vis2[a[i]]])
//				vis[a[i] - vis2[a[i]]] = 1, cnt++;
//		} else {
			int last = cnt;
			for (int j = a[i]; j >= 1; j--) {
				if (!vis[j]) {
					vis[j] = 1, cnt++;
//					cout << j << " ";
					break;
				}
			}
			if (cnt == last) {
				break;
			}
//		}
//		vis2[a[i]]++;f
	}
	cout << cnt;

	return 0;
}

