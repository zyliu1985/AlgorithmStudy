#include<bits/stdc++.h>
using namespace std;
int a[200010][4];
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1];
	for(int i=1;i<=n;i++)cin>>a[i][2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			if(a[i][j]){
				ans+=3;
				if(j==1&&i%2==1){
					if(a[i-1][j])ans--;
					if(a[i+1][j])ans--;
					if(a[i][j+1])ans--;
				}
				if(j==2&&i%2==1){
					if(a[i-1][j])ans--;
					if(a[i+1][j])ans--;
					if(a[i][j-1])ans--;
				}
				if(j==1&&i%2==0){
					if(a[i-1][j])ans--;
					if(a[i+1][j])ans--;
					if(a[i][j-1])ans--;
				}
				if(j==2&&i%2==0){
					if(a[i-1][j])ans--;
					if(a[i+1][j])ans--;
					if(a[i][j+1])ans--;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
