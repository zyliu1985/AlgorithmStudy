#include<bits/stdc++.h>
using namespace std;
int h[5010],n;
int calc(int left,int right){
	int res=0;
	for(int i=0;i<=(right-left)/2;i++){
		res += abs(h[left+i]-h[right-i]);
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int len=1;len<=n;len++){
		int ans=calc(0,len-1);
		for(int i=1;i<n-len+1;i++){
			ans = min(ans,calc(i,i+len-1));
		}
		cout<<ans;
		if(len!=n) cout<<" ";
	}
	return 0;
}
/*
7
3 1 4 1 5 9 2

4
1 3 5 6
*/
