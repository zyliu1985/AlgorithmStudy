#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,mp[3][200010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&mp[i][j]);
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==1){
				int cnt=0;
				for(int k=0;k<4;k++){
					int tx,ty;
					tx=i+dx[k];
					ty=j+dy[k];
					if(tx<1||tx>2||ty<1||ty>n){
						continue;
					}
					if(i==1){
						if(j%2!=0){
							if(k==0||k==2||k==3){
								if(mp[tx][ty]==1){
									cnt++;
								}
							}
						}
						else{
							if(k==0||k==2){
								if(mp[tx][ty]==1){
									cnt++;
								}
							}
						}
					}
					else if(i==2){
						if(j%2!=0){
							if(k==0||k==3||k==2){
								if(mp[tx][ty]==1){
									cnt++;
								}
							}
						}
						else{
							if(k==0||k==2){
								if(mp[tx][ty]==1){
									cnt++;
								}
							}
						}
					}
				}
				if(cnt==0){
					ans+=3;
				}
				else if(cnt==1){
					ans+=2;
				}
				else if(cnt==2){
					ans+=1;
				}
			}
		}
	}
	printf("%lld",ans);
}
