#include<bits/stdc++.h>
using namespace std;
int n,sum=0,sumn[5003],s;
int ans=1e9+8;
int a[5003];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			cout<<0<<" ";
			continue;
		}ans=1e9+8;
		for(int j=1;j<=n-i+1;j++){
			sumn[j]=0;
			s=j;
			if(i%2==0){
				for(int k=i;k>i/2;k--,s++){
					sum=(a[s]-a[j+k-1]);
					sumn[j]+=abs(sum);
					if(sumn[j]>=ans){
						break;
					}
				}
			}else{
				for(int k=i;k>i/2;k--,s++){
					sum=(a[s]-a[j+k-1]);
					sumn[j]+=abs(sum);
					if(sumn[j]>=ans){
						break;
					}
				}
			}
			ans=min(ans,sumn[j]);
		}
		cout<<ans<<" ";
	}
	return 0;
}
