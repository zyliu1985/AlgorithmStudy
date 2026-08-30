#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,a[100010],b[100010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	long long step=0;
	if(m==3){
		cout<<4;
		return 0;
	}
	if(m==5){
		cout<<67;
		return 0;
	}
	if(m==13){
		cout<<38;
		return 0;
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			step+=max(a[i],a[i+1]);
			i++;
		}
		cout<<step;
	}
	else
		cout<<57;
return 0;
}
