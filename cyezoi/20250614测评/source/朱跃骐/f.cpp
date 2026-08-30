#include<bits/stdc++.h>
using namespace std;
int a[3005],b[105],n,m,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	if(m==0){
		int x=0,y=0;
		for(int i=1;i<=n;i+=2) x+=a[i];
		for(int i=2;i<=n;i+=2) y+=a[i];
		printf("%d",max(x,y));
	}else if(m==1){
		for(int i=0;i<=n;i++){
			int x=0,y=0;
			for(int j=1;j<=n+1;j+=2){
				if(j<=i) x+=a[j];
				else if(j==i+1) x+=b[1];
				else x+=a[j-1];
			}
			for(int j=2;j<=n+1;j+=2){
				if(j<=i) y+=a[j];
				else if(j==i+1) y+=b[1];
				else y+=a[j-1];
			}
			ans=max(ans,max(x,y));
		}
		printf("%d",ans);
	}else{
		int x=0,y=0,t;
		for(int i=1;i<=n;i+=2) x+=a[i];
		for(int i=2;i<=n;i+=2) y+=a[i];
		t=max(x,y);
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=int(m/2.0+0.5);i++) t+=b[i];
		printf("%d",t);
	}
	return 0;
}
