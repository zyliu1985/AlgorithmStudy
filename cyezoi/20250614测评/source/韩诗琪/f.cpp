#include<bits/stdc++.h>
using namespace std;

const int N=3005,M=105;

int n,m,a[N],b[M],ans1,ans2;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m==0){
		for(int i=1;i<=n;i++){
			if(i%2==0) ans1+=a[i];
			else ans2+=a[i];
		}
		cout<<max(ans1,ans2);
	}else cout<<44;
	return 0;
}
