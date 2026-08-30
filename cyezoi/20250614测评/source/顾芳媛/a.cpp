#include<bits/stdc++.h>
using namespace std;
int n,sum[10];
char ya[100010],yb[100010],yc[100010],yd[100010],ye[100010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ya[i]>>yb[i]>>yc[i]>>yd[i]>>ye[i];
		sum[1]+=ya[i];
		sum[2]+=yb[i];
		sum[3]+=yc[i];
		sum[4]+=yd[i];
		sum[5]+=ye[i];
	}
	int maxn=0; 
	for(int i=1;i<=5;i++){
		if(sum[i]>maxn){
			maxn=sum[i];
		}
	}
	int out=0;
	for(int i=1;i<=5;i++){
		if(sum[i]==maxn){
			if(out==0){
				cout<<i;
				out++;
			}
			else{
				cout<<","<<i;
			}
		}
	}
	return 0;
}
