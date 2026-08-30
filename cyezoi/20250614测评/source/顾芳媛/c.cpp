#include<bits/stdc++.h>
using namespace std;
int n,h[5010];

int bala(int len,int high[]){
	int sum[5010];
	for(int l=1;l<=n-len+1;l++){
		int r=l+len-1;
		for(int i=l;i<=r/2;i++){
			sum[l]+=abs(high[l+i]-high[r-i]);
		}
	}
	int minn=1000000;
	for(int i=1;i<=n-len+1;i++){
		if(sum[i]<minn){
			minn=sum[i];
		}
	}
	return minn;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	cout<<0<<" ";
	for(int i=2;i<=n;i++){
		cout<<bala(i,h)<<" ";
	}
	return 0;
}
