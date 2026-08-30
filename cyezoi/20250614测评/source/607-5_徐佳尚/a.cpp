#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10];
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("\n");
		for(ll j=1;j<=5;j++){
			char c;
			scanf("%c",&c);
			if(c=='Y')a[j]++;
		}
	}
	vector<ll> ans;
	ll ma=-1;
	for(ll i=1;i<=5;i++){
		if(a[i]>ma){
			ma=a[i];
			ans.clear();
			ans.push_back(i);
		}
		else if(a[i]==ma){
			ans.push_back(i);
		}
	}
	for(ll i=0;i<ans.size();i++){
		printf("%lld",ans[i]);
		if(i<ans.size()-1)printf(",");
	}
	return 0;
}
