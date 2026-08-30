#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int f[105][200005];
int l[100005];
vector<int> v[100005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= 1e5; i++)
			v[i].clear();
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++){
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++){
				int x;
				cin >> x;
				v[i].push_back(x);
			}
		}
		f[0][1] = -1;
		for (int r = 1; r <= 100; r++){
			for (int i = 1; i <= n; i++){
				int end = 0;
				for (int j = 0; j < l[i]; j++){
					if (end){
						if (f[r][v[i][j]] != 0 && f[r][v[i][j]] != i) f[r][v[i][j]] = -1;
						else f[r][v[i][j]] = i;
					}
					if (f[r-1][v[i][j]] != 0 && f[r-1][v[i][j]] != i)
						end = k;
					end = max(end - 1, 0);
				}
			}
		}
		while (q--){
			int qa, qb;
			cin >> qa >> qb;
			if (f[qa][qb] == 0) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
	}
	return 0;
}



