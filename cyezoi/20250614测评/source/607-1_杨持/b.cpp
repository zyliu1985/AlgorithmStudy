#include<bits/stdc++.h>
#define N 200010
using namespace std;
int c;
int a[N][2];
int cnt;
int res;
signed main(){
	scanf("%d",&c);
	for(int i=1;i<=c;i++)scanf("%d",&a[i][0]);
	for(int i=1;i<=c;i++)scanf("%d",&a[i][1]);
	for(int i=1;i<=c;i++){
		cnt+=(a[i][0]+a[i][1]);
		if(a[i][0]&a[i+1][0])res++;
		if(a[i][1]&a[i+1][1])res++;
		if((i&1)&&(a[i][0]&a[i][1]))res++;
	}
	printf("%d",cnt*3-2*res);
}

