#include<bits/stdc++.h>//AT18???
#define ll long long
using namespace std;
ll n,a[3030],m,b[110],ans;
void dfs(ll _x,ll _sum){
	if(_x>=n){
		ans=max(ans,_sum+a[_x]);
		return;
	}
	if(_x==0){
		dfs(_x+1,_sum+a[_x]);
		dfs(_x+2,_sum+a[_x]);
	}
	else{
		dfs(_x+2,_sum+a[_x]);
		dfs(_x+3,_sum+a[_x]);
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
