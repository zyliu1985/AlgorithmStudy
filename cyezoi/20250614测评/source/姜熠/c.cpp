//C;
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int func(int l,int r){
	int ret=0;
	if(l==r)return 0;
	else{
		int ret1=0;
		int ret2=0;
		for(int i=0;i<=(r-l)/2;i++){
			ret1+=a[l+i];
			ret2+=a[l-i];
		}
		ret=abs(ret1-ret2);
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			cout<<"0 ";
			continue;
		}
		else{
			int minn=1e9;
			for(int l=1;l<=n;l++){
				int r=l+i-1;
				minn=(minn,func(l,r));
			}
			cout<<minn<<" ";
		}
	}
	return 0;
}
