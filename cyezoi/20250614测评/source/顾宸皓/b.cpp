#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
bool cz[3][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll s1,s2;
	ll cnt=0;
	for(s1=1;s1<=2;s1++){
		for(s2=1;s2<=n;s2++){
			cin>>cz[s1][s2];
			if(cz[s1][s2]){
				cnt+=3;
			}
		}
	}
	for(s1=1;s1<=2;s1++){
		for(s2=1;s2<=n;s2++){
			if(!cz[s1][s2]){
				continue;
			}
			if(s2%2==1 && cz[3-s1][s2]){
				cnt--;
			}
			if(cz[s1][s2+1]){
				cnt--;
			}
			if(cz[s1][s2-1]){
				cnt--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
