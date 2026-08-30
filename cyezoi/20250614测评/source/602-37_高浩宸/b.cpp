#include<bits/stdc++.h>
using namespace std;
int c,ans=0;
bool a[4][200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c;
	a[1][c+1]=0;a[2][c+1]=0;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				ans+=3;
				if(i==1){
					if(a[i][j-1]==1){
						ans-=2;
					}
				}else{
					if(j%2!=0){
						if(a[i-1][j]==1){
							ans-=2;
						}
					}
					if(a[i][j-1]==1){
						ans-=2;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
