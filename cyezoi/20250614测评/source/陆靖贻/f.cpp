#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005],b[105],ans1,ans2;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<n;i++){
		ans1+=a[i];
		ans2+=a[i+1];
	}
	cout<<max(ans1,ans2);
	return 0;
}
