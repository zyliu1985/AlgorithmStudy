#include<bits/stdc++.h>
using namespace std;

int n,h[5009],a[5009][5009],b[5009][5009],minn;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			a[i][j]=h[i]-h[j];
			if(a[i][j]<0){
				a[i][j]*=-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j][i]=a[j][i]+b[j+1][i-1];
		}
	}
	cout<<"0 ";
	for(int i=2;i<=n;i++){
		minn=1e9;
		for(int j=1,k=i;k<=n;j++,k++){
			minn=min(minn,b[j][k]);
		}
		cout<<minn<<" ";
	}
	return 0;
}

