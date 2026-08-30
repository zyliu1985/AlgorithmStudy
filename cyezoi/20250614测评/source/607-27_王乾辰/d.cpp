#include <bits/stdc++.h>
using namespace std;
//#define int ll
#define ll long long

set<int>s;

signed main(){
	int n,p;cin>>n>>p;
	for(int i=0;i<=n;i++)s.insert(i);
	for(int i=1;i<=p;i++){
		int x;cin>>x;
		auto it=--s.upper_bound(x);
		if(*it==0){
			cout<<i-1<<endl;
			return 0;
		}
		s.erase(it);
	}
	cout<<p<<endl;
	
	return 0;
}
