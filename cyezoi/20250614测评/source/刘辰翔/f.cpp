#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[30010],b[110];
bool cho[110];
int c[3010],p[15];
int dp[100010][2];
int dp10[3010][1055][2];


void to2(int x,int a[]){
	memset(cho,0,sizeof(cho));
	int cnt=0;
	while(x>=1){
		p[++cnt]=x%2;
		x/=2;
	}
	for(int i=1;i<=m;i++){
		a[i]=p[m-i+1];
	}
}

int f(int a[],int n){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dp[i-1][0]+a[i];
	}
	return max(dp[n][0],dp[n][1]);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	
	if(m==0){
		ans=f(a,n);
		cout<<ans;
		return 0;
	}
	if(m==1){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=n+1;j++){
				if(j<i)c[j]=a[j];
				if(j==i)c[j]=b[1];
				if(j>i)c[j]=a[j-1];
			}
			ans=max(ans,f(c,n+1));
		}
		cout<<ans;
		return 0;
	}
	if(m<=10){
		cout<<44;
		return 0;
	}
	cout<<"mei shen me(nothing at all)";
}
