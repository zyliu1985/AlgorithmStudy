#include<bits/stdc++.h>
using namespace std;
long long n,minn[5005],h[5005],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>h[i],minn[i]=LONG_LONG_MAX;
	for(int i=1;i<=n;++i){
		cnt=0;
		for(int j=0;j<=n;++j){
			if(i-j<1||i+j>n) break;
			cnt+=abs(h[i-j]-h[i+j]);
			minn[1+j+j]=min(minn[1+j+j],cnt);
		}
		cnt=0;
		for(int j=0;j<=n;++j){
			if(i-j<1||i+j+1>n) break;
			cnt+=abs(h[i-j]-h[i+j+1]);
			minn[2+j+j]=min(minn[2+j+j],cnt);
		}
	}
	for(int i=1;i<=n;++i) cout<<minn[i]<<" ";
	return 0;
}
