#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
bool vstd[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,x;
	cin>>x>>n;
	ll s,cnt=0;
	for(s=1;s<=n;s++){
		cin>>x;
		ll s1;
		while(vstd[x] && x>=1){
			x--;
		}
		if(x==0){
			cout<<cnt;
			return 0;
		}
		vstd[x]=1;
		cnt++;
	}
	cout<<n;
	return 0;
}
