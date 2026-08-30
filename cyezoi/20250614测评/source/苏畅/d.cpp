#include<bits/stdc++.h>//phigros
#define ll long long
using namespace std;
bool v[100010],ok;
ll n,m,a[100010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ok=0;
		for(int j=a[i];j>=1;j--){
			if(!v[j]){
				v[j]=1;
				ok=1;
				break;
			}
		}
		if(!ok){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
