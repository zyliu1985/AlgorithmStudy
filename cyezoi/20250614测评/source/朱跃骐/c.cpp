#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005],n,mn;
int f(int l,int r){
	return s[r]-s[l-1];
}
int calc(int l,int r,bool flag=0){
	if(!flag){
		int res=0;
		for(int i=0;i<=(r-l)>>1;i++) res+=abs(a[l+i]-a[r-i]);
		return res;
	}
	int t=(l+r+1)/2;
	if((r-l+1)&1) return f(t,r)-f(l,t);
	return f(t,r)-f(l,t-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(n<=300){
		for(int i=0;i<n;i++){
			mn=INT_MAX;
			for(int j=1;j<=n-i;j++) mn=min(mn,calc(j,j+i));
			printf("%d ",mn);
		}
	}else{
		for(int i=0;i<n;i++){
			mn=INT_MAX;
			for(int j=1;j<=n-i;j++) mn=min(mn,calc(j,j+i,1));
			printf("%d ",mn);
		}
	}
	return 0;
}
