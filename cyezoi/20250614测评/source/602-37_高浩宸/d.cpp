#include<bits/stdc++.h>
using namespace std;
int g,p,am,ans=0;
bool a[200005],x=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("data.in","r",stdin);
//	freopen("delta.out","w",stdout);
	cin>>g>>p;
	for(int i=1;i<=g;i++){
		a[i]=0;
	}
	for(int i=1;i<=p;i++){
		cin>>am;
		while(am!=0,am--){
			if(a[am]==0){
				a[am]=1;
				ans++;
				am=-1; 
				break;
			}
		}
		if(am!=-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
