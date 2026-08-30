#include<bits/stdc++.h>
using namespace std;
int g,p,a[100010],pre[100010],ans;
bool pl[100010];
int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	scanf("%d",&g);
	scanf("%d",&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&a[i]);
		pre[a[i]]=a[i];
	}
	for(int i=1;i<=p;i++){
		bool flag=0;
		int x;
		for(int j=pre[a[i]];j>=1;j--){
			if(pl[j]==0){
				flag=1;
				x=j;
				break;
			}
		}
		if(flag==1){
			ans++;
			pl[x]=1;
			pre[a[i]]=x;
		}
		else{
			break;
		}
	}
	printf("%d",ans);
}
