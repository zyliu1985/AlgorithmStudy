#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt[5],m,f;
string s[100005];
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		for(ll j=0;j<5;j++){
			cnt[j]+=(s[i][j]=='Y');
		}
	}
	m=*max_element(cnt,cnt+5);
	for(ll i=0;i<5;i++){
		if(cnt[i]==m){
			if(f){
				cout<<",";
			}
			f=1;
			cout<<i+1;
		}
	}
	return 0;
}

