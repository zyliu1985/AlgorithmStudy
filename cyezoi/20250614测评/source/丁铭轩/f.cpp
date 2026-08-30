#include<bits/stdc++.h>
using namespace std;

int n,m,x[3030],y[111],ans1=0,ans2=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>y[i];
	if(m==0){
		for(int i=1;i<=n;i=i+2) ans1=ans1+x[i];
		for(int i=2;i<=n;i=i+2) ans2=ans2+x[i];
		if(ans1>ans2) cout<<ans1;
		else cout<<ans2;
		return 0;
	}
	return 0;
}
