#include<bits/stdc++.h>
using namespace std;
#define int long long
int G,P;
int g[100010];
int d[100010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>G>>P;
	for(int i=1;i<=P;i++){
		cin>>g[i];
	}
	int left=0,right=P+1;
	while(left<right){
		int mid=(left+right)>>1;
		for(int i=1;i<=mid;i++){
			d[g[i]]++;
		}
		int ok=1;
		for(int i=1;i<=G;i++){
			d[i]+=d[i-1];
			if(d[i]>i){
				ok=0;
			}
		}
		if(ok){
			left=mid+1;
		}else{
			right=mid;
		}
	}
	cout<<left-1;
}
