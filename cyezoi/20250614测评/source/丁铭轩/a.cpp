#include<bits/stdc++.h>
using namespace std;

char k1[100010],k2[100010],k3[100010],k4[100010],k5[100010];
int ans[6]={0},mx=0,jl[6]={0},cnt=0;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>k1[i]>>k2[i]>>k3[i]>>k4[i]>>k5[i];
	for(int i=1;i<=n;i++){
		if(k1[i]=='Y') ans[1]++;
		if(k2[i]=='Y') ans[2]++;
		if(k3[i]=='Y') ans[3]++;
		if(k4[i]=='Y') ans[4]++;
		if(k5[i]=='Y') ans[5]++;
	}
	for(int i=1;i<=5;i++){
		if(ans[i]>mx){
			cnt=1;
			mx=ans[i];
			jl[1]=i;
		}
		if(ans[i]==mx){
			jl[cnt]=i;
			cnt++;
		}
	}
	for(int i=1;i<=cnt-1;i++) cout<<jl[i]<<" ";
	return 0;
}
