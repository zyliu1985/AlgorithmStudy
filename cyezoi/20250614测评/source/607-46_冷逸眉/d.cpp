#include <iostream>
using namespace std;
int G,P,g[100005],cnt,ans;
bool vis[100005],flag;
int main(){
	cin >> G >> P;
	for(int i = 1;i <= P;i++){
		cin >> g[i];
		if(flag) continue;
		int k = g[i];
		while(vis[k] && k >= 0) k--;
		if(k == 0 && flag == 0){
			flag = 1;
			ans = i - 1;
		}
		else vis[k] = 1;
	}
	cout << ans;
	return 0;
}
