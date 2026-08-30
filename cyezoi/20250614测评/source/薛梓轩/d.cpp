#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
int ga,p,g,f[110000],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ga>>p;
	for(int i=1;i<=p;i++){
		cin>>g;
		while(f[g]){
			g--;
			if(g==0){
				cout<<ans;
				return 0;
			}
		}
		f[g]=1;
		ans++;
	}
	return 0;
}
