#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
int n,h[6000],ans,dots[6000][6000];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=5500;i++)for(int j=1;j<=5500;j++)dots[i][j]=INT_MAX;
	for(int i=1;i<=n;i++){
		dots[i][1]=0;
		dots[i][2]=abs(h[i]-h[i+1]);
		for(int j=3;j<=min(i-1,n-i)*2+1;j++){
			if(j%2)dots[i][j]=dots[i][j-2]+abs(h[i+(j-1)/2]-h[i-(j-1)/2]);
			else dots[i][j]=dots[i][j-2]+abs(h[i+(j-1)/2+1]-h[i-(j-1)/2]);
		}
	}
	cout<<0<<" ";
	for(int i=2;i<n;i++){
		ans=INT_MAX;
		for(int dot=1;dot<=n;dot++)ans=min(ans,dots[dot][i]);
		cout<<ans<<" ";
	}
	ans=0;
	for(int i=0;i<=floor((n-1)/2.0);i++)ans+=abs(h[1+i]-h[n-i]);
	cout<<ans;
	return 0;
}
