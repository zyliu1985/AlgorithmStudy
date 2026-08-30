#include<bits/stdc++.h>
using namespace std;
int a[5005],m[5005];

int value(int l,int r){
	int val=0;
	while(l<r){
		val+=abs(a[l]-a[r]);
		l++,r--;
	}
	return val;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0<<" ";
	for(int i=2;i<=n;i++){
		memset(m,0x3f,sizeof(m));
		for(int j=1;j<=n-i+1;j++){
			m[i]=min(m[i],value(j,j+i-1));
			if(m[i]==0){
				break;
			}
		}
		cout<<m[i]<<" ";
	}
	return 0;
}
