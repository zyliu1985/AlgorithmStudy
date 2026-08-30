#include <bits/stdc++.h>
using namespace std;

int a[5005];
int main(){
	int n,sum,l,r,ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0;
	for(int i=2;i<=n;i++){
		ans=10e9;
		for(int j=1;j<=n-i+1;j++){
			sum=0;
			l=j;
			r=j+i-1;
			for(int k=0;k<=(r-l)/2;k++){
				sum += abs(a[l+k]-a[r-k]);
			}
			ans = min(ans,sum);
		}
		cout<<" "<<ans;
	}
}
	
