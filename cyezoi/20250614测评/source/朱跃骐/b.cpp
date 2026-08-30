#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[2][200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) ans+=3;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[1][i]){
			if(i==1) ans-=a[1][2]+a[2][1];
			else if(i==n) ans-=a[1][n-1]+((n&1)&&a[2][n]);
			else ans-=a[1][i-1]+a[1][i+1]+((i&1)&&a[2][i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[2][i]){
			if(i==1) ans-=a[2][2]+a[1][1];
			else if(i==n) ans-=a[2][n-1]+((n&1)&&a[1][n]);
			else ans-=a[2][i-1]+a[2][i+1]+((i&1)&&a[1][i]);
		}
	}
	printf("%d",ans);
	return 0;
}
