#include<bits/stdc++.h>//ÎÒÏ²»¶Äã 
#define ll long long
using namespace std;
bool ok;
char c;
ll n,ans[1000010],maxn;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y')ans[j]++;
		}
	}
	for(int i=1;i<=5;i++){
		maxn=max(ans[i],maxn);
	}
	for(int i=1;i<=5;i++){
		if(ans[i]==maxn&&!ok){
			cout<<i;
			ok=1;
		}
		else if(ans[i]==maxn&&ok){
			cout<<","<<i;
		}
	}
	return 0;
}
