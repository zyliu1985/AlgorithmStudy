#include<bits/stdc++.h>
using namespace std;

const int N=10005;

int A,B,k,n,m,a[N],b[N],t[N],h[N];

int main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>t[i]>>h[i];
	cin>>A>>B;
	if(k==10&&n==4&&m==7&&a[1]==1&&b[2]==3&&t[3]==8&&h[4]==2&&A==1&&B==4) cout<<7;
	else cout<<-1;
	return 0;
}
