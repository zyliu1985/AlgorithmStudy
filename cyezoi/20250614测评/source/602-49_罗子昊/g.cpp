#include<bits/stdc++.h>
using namespace std;
int n,a[3010],m,b[110],ans;
struct node{
	int num,id;
	char c;
}p[3010];
void dfs0(int u,int sum,bool pre){
	if(u==n+1){
		ans=max(ans,sum);
		return;
	}
	if(pre==0){
		dfs0(u+1,sum+a[u],1);
		dfs0(u+1,sum,0);
	}
	else{
		dfs0(u+1,sum,0);
	}
}
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i].num=a[i];
		p[i].id=i;
		p[i].c='A';
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		p[n+i].num=b[i];
		p[n+i].id=i;
		p[n+i].c='B';
	}
	sort(p+1,p+n+m+1,cmp);
	if(m==0){
		dfs0(1,0,0);
	}
	else if(m==1){
		int tmp1=0,tmp2=0;
		for(int i=1;i<=n;i++){
			if(i%2!=0){
				tmp1+=a[i];
			}
			else if(i%2==0){
				tmp2+=a[i];
			}
			ans=max(tmp1,tmp2);
		}
	}
	printf("%d",ans);
}
