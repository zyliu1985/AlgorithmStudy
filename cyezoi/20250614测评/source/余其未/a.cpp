#include<bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;
ll n,ans[10],k,t,x[5];
string s;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		for(ll j=0;j<5;j++) x[j]+=(s[j]=='Y'?1:0);
	}
	for(ll i=0;i<5;i++) if(x[i]>x[max(0ll,t-1)]) t=i+1;
	for(ll i=0;i<5;i++) if(x[i]==x[t-1]) ans[++k]=i+1;
	for(ll i=1;i<k;i++) cout<<ans[i]<<",";
	cout<<ans[k];
	return 0;
}
