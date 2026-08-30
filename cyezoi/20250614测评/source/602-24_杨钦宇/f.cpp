#include<bits/stdc++.h>
using namespace std;
int N,M,A[3001],B[101],f[3001][2],C[3002];
int main(){
	//freopen("f.in","r",stdin);
	cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	cin>>M;
	for(int i=1;i<=M;i++)cin>>B[i];
	
	if(M==0){
		f[0][0]=f[0][1]=0;
		for(int i=1;i<=N;i++){
			f[i][0]=max(f[i-1][0],f[i-1][1]);
			f[i][1]=A[i]+f[i-1][0];
		}
		cout<<max(f[N][1],f[N][0]);
	}
	
	if(M==1){
		int maxn=0;
		for(int i=1;i<=N+1;i++){
			for(int j=1;j<i;j++)C[j]=A[j];
			for(int j=i+1;j<=N+1;j++)C[j]=A[j-1];
			C[i]=B[1];
			
			f[0][0]=f[0][1]=0;
			for(int j=1;j<=N+1;j++){
				f[j][0]=max(f[j-1][0],f[j-1][1]);
				f[j][1]=C[j]+f[j-1][0];
			}
			maxn=max(maxn,max(f[N+1][1],f[N+1][0]));
		}
		cout<<maxn;
	}
	return 0;
}

