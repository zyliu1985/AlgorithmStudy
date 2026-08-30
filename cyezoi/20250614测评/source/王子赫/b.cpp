#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int ans = 0;
bool vis[5][N];

int main(){
	int n;
	scanf("%d",&n);//triangle need (3-nearby triangle number)
	
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= n;j++){
			int a;
			scanf("%d",&a);
			vis[i][j] = a;
		}
	}
	
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= n;j++){
			if(!vis[i][j]) continue;
			ans+=3;
			if(vis[i][j-1]) ans--;
			if(vis[i][j+1]) ans--;
			
			if(j%2==1){
				if(vis[i-1][j]) ans--;
				if(vis[i+1][j]) ans--;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
