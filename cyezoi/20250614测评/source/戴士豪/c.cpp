#include<bits/stdc++.h>
using namespace std;

int n,a[5100];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int ans=1e9;
		for(int j=1;j<=n-i+1;j++){
			int l=j,r=j+i-1,cnt=0;
			while(l<r){
				cnt+=abs(a[r]-a[l]);
				l++;
				r--;
				if(cnt>ans)break;
			}
			ans=min(ans,cnt);
		}
		printf("%d ",ans);
	}
	return 0;
}
