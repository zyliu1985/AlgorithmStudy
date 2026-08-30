#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[3009],b[109];
namespace M1{
	int dp[3009][2];//1-i with j Ms left
	void solve(){
		for(int i=1;i<=n+1;i++){
			for(int j=0;j<=m;j++){
				if(j==0) dp[i][j]=max(dp[i-1][j],dp[i-2][j]+a[i]);
				else{
					dp[i][j]=max(dp[i-1][j],dp[i-2][j]+a[i]);
					dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]+a[i],dp[i-2][j-1]+b[j]));
				}
			}
		}
		cout<<max(dp[n+1][1],dp[n+1][0]);
	}
}
namespace sol{
	int dp[3009][109][109][2],ans;//1-i with j small Ms &k big Ms killed
	void solve(){
		sort(b+1,b+m+1);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=m;k++){
					if(j+k>m) break;		
					dp[i][j][k][0]=max(dp[i-1][j][k][0],dp[i-1][j][k][1]);
					dp[i][j][k][1]=dp[i-1][j][k][0]+a[i];
					if(k>0) dp[i][j][k][0]=max(dp[i][j][k][0],dp[i-1][j][k-1][0]+b[m-k+1]);
					if(j>0) dp[i][j][k][1]=max(dp[i][j][k][1],max(dp[i-1][j-1][k][0],dp[i-1][j-1][k][1])+a[i]);
					if(i==n){
						for(int ii=1;ii<=(m-j-k)/2;ii++) dp[i][j][k][1]+=b[m-k-ii+1];
						for(int ii=1;ii<=(m-j-k+1)/2;ii++) dp[i][j][k][0]+=b[m-k-ii+1];
					//cout<<j<<' '<<k<<" ("<<dp[i][j][k][0]<<','<<dp[i][j][k][1]<<")\n";
						ans=max(ans,max(dp[i][j][k][0],dp[i][j][k][1]));
					}
				}
			}
		}
		cout<<ans;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m<=1) M1::solve();
	else sol::solve();
	return 0;
}

