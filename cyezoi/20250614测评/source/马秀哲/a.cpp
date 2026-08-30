#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[6];
signed main(){
	int n;
	cin>>n;
	char b;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>b;
		if(b=='Y') a[1]++;
		cin>>b;
		if(b=='Y') a[2]++;
		cin>>b;
		if(b=='Y') a[3]++;
		cin>>b;
		if(b=='Y') a[4]++;
		cin>>b;
		if(b=='Y') a[5]++;
	}
	maxx=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
	int ans=0;
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			ans+=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			if(cnt==ans-1){
				cout<<i;
			}
			else{
				cout<<i<<",";
			}
			cnt++;
		}
	}
	return 0;
}
