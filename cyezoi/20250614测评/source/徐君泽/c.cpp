#include<bits/stdc++.h>
using namespace std;

int n;
int h[5000];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=1;i<=n;i++){
		int minn=INT_MAX;
		for(int j=0;j<=n-i;j++){
			int l=j,r=j+i-1;
			int ans=0;
			for(int k=0;k<=(r-l)/2;k++){
				  int nl=l+k,nr=r-k;
				  ans+=abs(h[nl]-h[nr]);
			}
			minn=min(minn,ans);
		}
		cout<<minn<<" ";
	}		
}
