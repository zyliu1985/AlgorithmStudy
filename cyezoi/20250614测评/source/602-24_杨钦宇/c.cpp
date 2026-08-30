#include<bits/stdc++.h>
using namespace std;
int N,h[10001],f[10001][5001],ans[5001];
int main(){
	//freopen("c.in","r",stdin);
	//freopen("c.ans","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)cin>>h[i];
	for(int i=N;i>=1;i--)h[i*2-1]=h[i];
	for(int i=1;i<=N;i++)h[i*2]=0;
	for(int i=1;i<=N;i++)ans[i]=2147483647;
	/*
	for(int i=1;i<=2*N;i++)cout<<h[i]<<" ";
	cout<<endl;
	*/
	for(int i=1;i<=2*N;i++){
		for(int j=1;j<min(i,2*N-i);j++){
			f[i][j]=f[i][j-1]+abs(h[i+j]-h[i-j]);
		}
	}
	for(int i=1;i<=2*N;i++){
		if(i%2==1){
			for(int j=1;j<min(i,2*N-i);j++)
				ans[j/2*2+1]=min(ans[j/2*2+1],f[i][j]);
		}else{
			for(int j=1;j<min(i,2*N-i);j++){
				ans[(j+1)/2*2]=min(ans[(j+1)/2*2],f[i][j]);
			}
		}
	}
	for(int i=1;i<=N;i++)cout<<ans[i]<<" ";
	return 0;
}

