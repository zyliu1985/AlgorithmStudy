#include <bits/stdc++.h>
using namespace std;
int n,m,cnt = 0;
bool vis[2010];
int main(){
	cin >> n >> m;
	for (int i = 1;i <= m;i++){
		int x;
		cin >> x;
		if (!vis[x]) vis[x] = 1,cnt++;
		else{
			bool flag = 1;
			for (int i = x - 1;i >= 1 && flag;i--){
				if (!vis[i]){
					vis[i] = 1;
					cnt++;
					flag = 0;
				}
			}
			if (flag) break;
		}
	}
	cout << cnt;
}
