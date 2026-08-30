#include <bits/stdc++.h>
using namespace std;
int n,h[5010],a[5001][5001];
int f(int l,int r){
	if(a[l][r]>=0)return a[l][r];
	if(r-l==1){
		int x=abs(h[r]-h[l]);
		a[l][r]=x;
		return x;
	}
	if(r==l){
		a[l][r]=0;return 0;
	}
	int x=f(l+1,r-1)+abs(h[r]-h[l]);
	a[l][r]=x;
	return x;
}
int main(){
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(a,-1,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> h[i];
	}
	for(int i=1;i<=n;i++){
		int man=INT_MAX;
		for(int j=1;j+i-1<=n;j++){
			man=min(man,f(j,j+i-1));
		}
		cout << man<<" ";
	}
	return 0;
}
