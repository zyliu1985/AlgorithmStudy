#include<bits/stdc++.h>
using namespace std;
long long num,ans;
int g,p,a[100005],vis[100005];
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i];if(i>=g)a[i]=0;
		vis[a[i]]++;
	}
	for(int i=g;i>=1;i--){
		if(vis[i]>0){
			ans++;
			vis[i]--;
			if(vis[i]>0){
				num+=vis[i];
			}
		}
		if(vis[i]==0){
			if(num>0){
				num--;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
