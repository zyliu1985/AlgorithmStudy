#include<bits/stdc++.h>
using namespace std;
int g,p,ans;
bool f[100005],flag;
int main() {
//	freopen("data.in","r",stdin);
//	freopen("data.ou","w",stdout);
	cin>>g>>p;
	for(int i=1;i<=p;i++) {
		int x;
		scanf("%d",&x);
		if(flag) continue;
		bool ok=0;
		for(int j=x;j>=1;j--) {
			if(!f[j]) {
				ok=1,f[j]=1,ans++;
				break;
			}
		}
		if(!ok) {
			flag=1,cout<<ans;
			return 0;
		}
	}
	if(!flag) cout<<ans;
	return 0;
}
