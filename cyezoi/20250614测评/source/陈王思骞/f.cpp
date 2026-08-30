#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,p[3110];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>m;
	for(int i=n+1;i<=n+m;i++)
		cin>>p[i];
	int sum=n+m,ps;
	if(sum%2==0)
		ps=sum/2;
	else
		ps=sum/2+1;
	for(int i=1;i<=sum;i++)
		for(int j=i+1;j<=sum;j++)
			if(p[i]<p[j])
				swap(p[i],p[j]);
	int ans=0;
	for(int i=1;i<=ps;i++)
		ans+=p[i];
	cout<<ans;
	return 0;
}
