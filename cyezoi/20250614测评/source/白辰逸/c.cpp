#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long n,ans=2e5+10,nn=0;
int main(){
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<0<<' ';
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long ll=i+j-1;
			for(int k=j;k<=ll;k++){
				nn+=abs(a[k]-a[ll]);
				ll--;
				if(ll<k)
				break;
			}
			ans=min(ans,nn);
		}
		if(i!=n)
		cout<<ans-1<<' ';
		ans=2e5+10;
		nn=0;
	}
return 0;
}
