#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int h[N],n;
long long sum[N][N];
inline long long find(int l,int r){
	long long sum=0;
	while(l<=r){
		sum+=abs(h[l]-h[r]);
		l++,r--;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr), cout.tie (nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++){
		long long ans=1e9;
		for(int l=1,r=i;r<=n;l++,r++) ans=min(ans,find(l,r));
		cout<<ans<<" ";
	}
}
