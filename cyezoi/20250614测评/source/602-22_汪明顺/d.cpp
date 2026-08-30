#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int G, P, ans;
bool vis[N];
signed main(){
	memset(vis, 0, sizeof(vis));
	cin >> G >> P;
	for(int i = 1; i <= P; i++){
		int x;
		cin >> x;
		bool flag = false;
		for(int j = x; j >= 1; j--){
			if(vis[j] == false){
				vis[j] = true;
				ans++;
				flag = true;
				break;
			}
		}
		if(!flag)
			break;
	}
	cout << ans << '\n';
	return 0;
}
