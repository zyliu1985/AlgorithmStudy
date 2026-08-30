#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<=300){
		int h[n];
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		for(int i=1;i<=n;i++){
			int mi=5e8+5;
			for(int j=0;j<n-i+1;j++){
				int ans=0;
				for(int k=0;j+k<j+i-k-1;k++){
					ans+=abs(h[j+k]-h[j+i-k-1]);
				}
				mi=min(mi,ans);
			}
			cout<<mi<<" ";
		}
	}
	else{
		int h[n],s[n];
		for(int i=0;i<n;i++){
			cin>>h[i];
			if(i==0){
				s[i]=h[i];
			}
			else{
				s[i]=s[i-1]+h[i];
			}
		}
		for(int i=1;i<=n;i++){
			int mi=5e8+5;
			for(int j=0;j<=n-i;j++){
				int k=i/2,ans;
				if(j==0){
					ans=(s[j+i-1]-s[j+i-1-k])-(s[j+k-1]);
				}
				else{
					ans=(s[j+i-1]-s[j+i-1-k])-(s[j+k-1]-s[j-1]);
				}
				mi=min(mi,ans);
			}
			cout<<mi<<" ";
		}
	}
	return 0;
}

