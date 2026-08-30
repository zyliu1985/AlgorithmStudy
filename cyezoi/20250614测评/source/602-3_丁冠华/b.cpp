#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,a[3][200020],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=2;i++)for(int j=1;j<=n;j++){
		cin>>a[i][j];
		if(a[i][j]==1)ans+=3;
		if(a[i][j]==1&&a[i][j-1]==1)ans-=2;
		if((j&1)&&a[i][j]==1&&a[i-1][j]==1)ans-=2;
	}
	cout<<ans;
	return 0;
}
