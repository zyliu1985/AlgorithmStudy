#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[10009],ans[5009],now;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i*2-1];
		ans[i]=1e17;
	} 
	for(int i=1;i<n*2;i++){
		now=0;
		for(int j=0;j<min(i,n*2-i);j++){
			now+=abs(h[i-j]-h[i+j]);
			if(i%2) ans[1+j-j%2]=min(ans[1+j-j%2],now);
			else ans[j+j%2]=min(ans[j+j%2],now);
			//cout<<i<<' '<<j<<' '<<now<<endl;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}

