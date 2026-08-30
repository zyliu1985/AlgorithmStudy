#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[2][200005],cnt,cnt1;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(ll i=0;i<=1;i++){
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			cnt+=a[i][j];
		}
	}
	for(ll i=0;i<=1;i++){
		for(ll j=2;j<=n;j++){
			if(a[i][j-1]&&a[i][j]){
				cnt1++;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if((i&1)&&a[0][i]&&a[1][i]){
			cnt1++;
		}
	}
	cout<<3*cnt-2*cnt1;
	return 0;
}

