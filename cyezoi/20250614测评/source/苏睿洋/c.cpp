#include<bits/stdc++.h>
using namespace std;

int n,a[5050],s[5050]={0};
void solve(){
	for(int i=2;i<=n;i++){
		int ans=0;
		for(int j=1;i+j-1<=n;j++){
			int res=0;
			for(int k=1;k<=i/2;k++) res+=abs(a[j+k-1]-a[i+j-k]);
			if(j!=1) ans=min(res,ans);
			else ans=res;
		}
		cout<<ans<<" ";
	}
}
void wrong(){
	for(int i=2;i<=n;i++){
		int ans=0;
		for(int j=1;i+j-1<=n;j++){
			int res=s[i+j-1]-s[i/2+j-1]*2+s[j-1];
			if(i%2==1) res-=a[i/2+j];
			res=abs(res);
			if(j!=1) ans=min(res,ans);
			else ans=res;
		}
		cout<<ans<<" ";
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cout<<0<<" ";
	if(n<=300) solve();
	else wrong();
	return 0;
}
