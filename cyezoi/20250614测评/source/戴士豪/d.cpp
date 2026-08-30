#include<bits/stdc++.h>
using namespace std;

int g,p,a,vis[100010],f,ans=0;

int main(){
	scanf("%d%d",&g,&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&a);
		f=0;
		for(int j=a;j>=1;j--){
			if(vis[j]==0){
				vis[j]=1;
				f=1;
				ans++;
				break;
			}
		}
		if(f==0){
			cout<<ans;
			return 0;
		}
	}
	printf("%d",ans);
	return 0;
}
