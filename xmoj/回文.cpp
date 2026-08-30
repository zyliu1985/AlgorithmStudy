#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[500005], b[500005];
int x[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n;
		cin >> n;
		for (int i = 1; i <= 2 * n; i++){
			cin >> x[i];
			if (a[x]) b[x] = i;
			else a[x] = i;
		}
		int l = 1, r = 2 * n, lc, rc;
		string ans;
		bool flag = false;
		
		while (l < lc || rc < r){
			
		}
	}
	return 0;
}

