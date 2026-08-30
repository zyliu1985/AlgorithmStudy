#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int n;
int val[N];
int a[N][N];
int ans[N];
int main(){
	memset(ans,0x3f,sizeof(ans));
	memset(a,0x3f,sizeof(a));
	ans[1] = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&val[i]);
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			a[i][j] = abs(val[i]-val[j]);
	
	/*for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j]>1e9) printf("X ");
			else printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	
	for(int i = 2;i <= n-1;i++){
		int xi = i-1,xj = i+1;
		int sum = 0,cnt = 1;
		while(xi > 0&&xj <= n){
			sum+=a[xi][xj];
			cnt+=2;
			ans[cnt] = min(ans[cnt],sum);
			xi--;xj++;
		}
	}
	for(int i = 1;i <= n-1;i++){
		int xi = i,xj = i+1;
		int sum = 0,cnt = 0;
		while(xi > 0&&xj <= n){
			sum+=a[xi][xj];
			cnt+=2;
			ans[cnt] = min(ans[cnt],sum);
			xi--;xj++;
		}
	}
	
	for(int i = 1;i <= n;i++) printf("%d ",ans[i]);
	return 0;
}
