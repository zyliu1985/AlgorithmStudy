#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
int num[1005][1005], last[1005][1005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, t, m;
	cin >> n >> t >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			update(i, j, i - 1, j);
			
			update(i, j, i - 1, j - 1);
		}
	return 0;
}



