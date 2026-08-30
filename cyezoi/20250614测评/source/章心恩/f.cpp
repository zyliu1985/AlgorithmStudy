#include<bits/stdc++.h>
using namespace std;
int n1[3005],n2[3005][2];
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}
	cin>>m;
	if(m==0){
		n2[0][0]=0;
		n2[0][1]=n1[0];
		for(int i=1;i<n;i++){
			n2[i][0]=max(n2[i-1][0],n2[i-1][1]);
			n2[i][1]=n2[i-1][0]+n1[i];
		}
		cout<<max(n2[n-1][1],n2[n-1][0]);
	}else if(m==1){
		cin>>n1[n];
		int maxn=0;
		for(int i=n;i>0;i++){
			n2[0][0]=0;
			n2[0][1]=n1[0];
			for(int i=1;i<n;i++){
				n2[i][0]=max(n2[i-1][0],n2[i-1][1]);
				n2[i][1]=n2[i-1][0]+n1[i];
			}
			maxn=max(maxn,max(n2[n-1][1],n2[n-1][0]));
		}
		cout<<maxn;
	}
}
