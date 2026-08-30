#include<bits/stdc++.h>
using namespace std;
long long c,ans;
bool g[3][200005];
int main() {
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	cin>>c;
	for(int i=1;i<=c;i++) {
		cin>>g[1][i];
		if(g[1][i]==1) ans+=3;
	}
	for(int i=1;i<=c;i++) {
		cin>>g[2][i];
		if(g[2][i]==1) ans+=3;
	}
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=c;j++){
			if(g[i][j]) {
				if(g[i-1][j]&&j%2!=0)
					ans-=2;
				if(g[i][j-1]) ans-=2;
			}
		}
	}
	cout<<ans;
	return 0;
}
