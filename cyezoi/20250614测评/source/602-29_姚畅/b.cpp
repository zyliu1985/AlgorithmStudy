#include <bits/stdc++.h>
using namespace std;
int c,cnt,cnt2;
bool a[200001],b[200000];
int main(){
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >>c;
	for(int i=1;i<=c;i++){
		cin>> a[i];
		cnt2+=a[i];
		if(i>1&&a[i-1]&&a[i])cnt++;
	}
	for(int i=1;i<=c;i++){
		cin>> b[i];
		cnt2+=b[i];
		if(i>1&&b[i-1]&&b[i])cnt++;
	}
	for(int i=1;i<=c;i+=2)if(a[i]&&b[i])cnt++;
	cout <<cnt2*3-cnt*2;
	return 0;
}
