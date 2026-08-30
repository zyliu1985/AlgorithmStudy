#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int g,p,a[100010],i;
bool vis[100010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>g>>p;
	for(i=1;i<=p;i++)cin>>a[i];
	for(i=1;i<=p;i++){
		bool f=1;
		for(int j=a[i];j;j--){
			if(vis[j]==0){
				vis[j]=1,f=0;
				break;
			}
		}
		if(f){
			i--;
			break;
		}
	}
	cout<<i;
	return 0;
}
