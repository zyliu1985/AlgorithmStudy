#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 15;
ll c, cnt = 0, rep = 0, ans;
bool a[maxn][4], vis[maxn][4];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(a, 0, sizeof(a));
	
	cin >> c;
	for (int j = 1; j <= 2; j++){
		for (int i = 1; i <= c; i++){
			cin >> a[i][j];
			if (a[i][j] == 1) cnt++;
		}
	}
	for (int i = 1; i <= c; i++){
		for (int j = 1; j <= 2; j++){
			if (a[i][j] == 1){
				if (a[i - 1][j] == 1 && !vis[i - 1][j]) rep++;
				if (a[i + 1][j] == 1 && !vis[i + 1][j]) rep++;
				if (i % 2 == 1){
					if (j == 1){
						if (a[i][2] == 1 && !vis[i][2]) rep++;
					}
					else{
						if (a[i][1] == 1 && !vis[i][1]) rep++;
					}
				}
				vis[i][j] = 1;
			}
		}
	}
	ans = cnt * 3 - rep * 2;
	//cout << cnt << endl;
	//cout << rep << endl;
	cout << ans << endl;
	return 0;
}
