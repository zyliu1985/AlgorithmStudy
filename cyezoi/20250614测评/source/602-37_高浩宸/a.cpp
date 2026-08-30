#include<bits/stdc++.h>
using namespace std;
int a[7],maxn=0,n,ansn=0,ans[7];
char s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>s;
			if(s=='Y'){
				a[j]++;
			}
		}
	}
	for(int j=1;j<=5;j++){
		maxn=max(maxn,a[j]);
	}
	for(int i=1;i<=5;i++){
		if(a[i]==maxn){
			ansn++;
			ans[ansn]=i;
		}
	}
	for(int i=1;i<=ansn;i++){
		if(i!=ansn){
			cout<<ans[i]<<",";
		}else{
			cout<<ans[i];
		}
	}
	return 0;
}
