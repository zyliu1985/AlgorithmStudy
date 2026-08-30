#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,all;
bool a[200009],b[200009];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) all++;
		if(a[i]&&a[i-1]) cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]) all++;
		if(b[i]&&b[i-1]) cnt++;
		if(i%2&&a[i]&&b[i]) cnt++;
	}
	cout<<all*3-cnt*2;
	return 0;
}

