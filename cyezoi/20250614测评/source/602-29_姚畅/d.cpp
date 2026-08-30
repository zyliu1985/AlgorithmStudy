#include <bits/stdc++.h>
using namespace std;
int n,p,g[100001],m[100001],ans;
bool o[100001];
int main(){
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >>n>>p;
	for(int i=1;i<=p;i++){
		cin>>g[i];
		bool f=0;
		for(int j=g[i];j>=1;j--){
			if(o[j]==0){
				o[j]=1;
				f=1;
				break;
			}
		}
		if(!f)break;
		ans++;
	}
	cout << ans;
	return 0;
}
