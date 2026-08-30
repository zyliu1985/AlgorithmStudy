#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100100],b[100100];
signed main(){
	int n,m;
	cin>>n>>m;
	int ans;
	for(int j=1;j<=n;j++){
			b[j]=0;
			
		}
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=a[i];j<=n;j++){
			b[j]+=1;
			if(b[j]>j){
				ans=i-1;
				goto bbb;
			}
		}
	}
	ans=n;
	bbb:
		cout<<ans;
	return 0;
}
