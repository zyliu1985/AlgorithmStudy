#include <bits/stdc++.h>
using namespace std;

const int N=100010;

int n,m,c,vis[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&c);
		int cnt=c;
		while(vis[cnt]==1)
			--cnt;
		if(cnt==0){
			printf("%d",i-1);
			break;
		}
		vis[cnt]=1;
	}
	return 0;
}
