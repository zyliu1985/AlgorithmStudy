#include<bits/stdc++.h>
using namespace std;

const int N=200005;
 
int c,cnt,ans; 
char a[N],b[N];

int main()
{
	cin>>c;
	for(int i=1;i<=c;i++) cin>>a[i];
	for(int i=1;i<=c;i++) cin>>b[i];
	for(int i=1;i<=c;i++){
		if(a[i]=='1'&&a[i-1]=='1') cnt++;
		if(a[i]=='1') ans++;
	}
	for(int i=1;i<=c;i++){
		if(b[i]=='1'&&b[i-1]=='1') cnt++;
		if(b[i]=='1') ans++;
	}
	for(int i=1;i<=c;i++)
		if(a[i]=='1'&&b[i]=='1') cnt++;
	ans=ans*3-cnt*2;
	cout<<ans;
	return 0;
}
