#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,p;
int g[N];
int ans;
set<int> S;
signed main(){
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++)S.insert(i);
	for(int i=1;i<=p;i++)scanf("%d",&g[i]);
	for(int i=1;i<=p;i++){
		auto it=S.upper_bound(g[i]);
		if(it==S.begin()){
			printf("%d",ans);
			exit(0);
		}
		S.erase(--it);
		ans++;
	}
	printf("%d",ans);
}

