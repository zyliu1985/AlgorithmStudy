#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool b[3][200005];
char c;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		if(b[1][i]==1){
			if(b[1][i-1]==1){
				ans-=1;
			}
			else{
				ans+=1;
			}
			ans+=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[2][i]==1){
			if(b[2][i-1]==1){
					ans-=1;
			}
			else{
				ans+=1;
			}
			if(i%2&&b[1][i]){
				ans-=1;
			}
			else{
				ans+=1;
			}
			ans+=1;
		}	
	}
	printf("%d",ans);
	return 0;
}
