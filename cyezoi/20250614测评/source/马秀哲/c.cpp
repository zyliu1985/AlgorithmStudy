#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5100][5100],b[5100],maxx[5100];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		maxx[i]=12000000;
	}
	for(int i=1;i<=n;i++){
		a[1][i]=0;
	}
	maxx[1]=0;
	for(int i=2;i<=n;i++){
		a[2][i]=abs(b[i]-b[i-1]);
		maxx[2]=min(maxx[2],a[2][i]);
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[i][j]=a[i-2][j-1]+abs(b[j]-b[j-i+1]);
			maxx[i]=min(maxx[i],a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<maxx[i]<<" ";
	}
	return 0;
}
