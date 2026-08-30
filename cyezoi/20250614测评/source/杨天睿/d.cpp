#include<bits/stdc++.h>
using namespace std;
int g,p,x;
bool f[100005],isok;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>g>>p;
	for(int i=1;i<=p;++i){
		isok=0;
		cin>>x;
		for(int j=x;j>0;--j)
			if(!f[j]){
				f[j]=1;
				isok=1;
				break;
			}
		if(!isok){
			cout<<i-1;
			return 0;
		}
	}
	cout<<p;
	return 0;
}

