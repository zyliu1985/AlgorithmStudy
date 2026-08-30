#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll s1,s2;
	for(s1=1;s1<=n;s1++){
		string cx;
		cin>>cx;
		for(s2=0;s2<=4;s2++){
			if(cx[s2]=='Y'){
				a[s2+1]++;
			}
		}
	}
	bool flag=1;
	for(s1=1;s1<=5;s1++){
		if(a[s1]==*max_element(a+1,a+6)){
			if(!flag){
				cout<<",";
			}
			flag=0;
			cout<<s1;
		}
	}
	return 0;
}
