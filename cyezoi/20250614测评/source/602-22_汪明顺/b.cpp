#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000010;
int vis[2][N];
int n, ans;
signed main(){
	memset(vis, 0, sizeof(vis));
	cin >> n;
	for(int i = 0; i <= 1; i++){
		for(int j = 1; j <= n; j++)
			cin >> vis[i][j];
	}
	for(int i = 0; i <= 1; i++){
		for(int j = 1; j <= n; j++){
			if(vis[i][j] == 1){
				if(i == 0){
					if(vis[i][j - 1] == 1)
						ans += 1;
					else
						ans += 3;
				}
				else{
					if(vis[i][j - 1] == 1){
						ans += 1;
						if(vis[i - 1][j] == 1){
							if(j % 2 == 1)
								ans -= 2;
						}
					}
					else if(vis[i - 1][j] == 1){
						if(j % 2 == 1)
							ans += 1;
						else
							ans += 3;
					}
					else
						ans += 3;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
