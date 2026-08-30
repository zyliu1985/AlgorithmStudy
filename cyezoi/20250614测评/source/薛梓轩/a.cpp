#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
int n,a[10],maxx=INT_MIN,f;
char t;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>t;
			if(t=='Y')a[j]++;
		}
	}
	for(int i=1;i<=5;i++)maxx=max(maxx,a[i]);
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			if(f==0)cout<<i,f=1;
			else cout<<","<<i;
		}
	}
	return 0;
}
