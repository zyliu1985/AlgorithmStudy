#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

int a[200005],b[200005];
signed main(){
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],ans+=3*a[i];
	for(int i=1;i<=n;i++)cin>>b[i],ans+=3*b[i];
	for(int i=1;i<=n;i++){
		if(i%2==1&&a[i]&&b[i])ans-=2;
	}
	for(int i=1;i<n;i++){
		if(a[i]&&a[i+1])ans-=2;
		if(b[i]&&b[i+1])ans-=2;
	}
	cout<<ans<<endl;
	
	return 0;
}
