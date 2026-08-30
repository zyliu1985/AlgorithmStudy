#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n;
char s[N][5];
int cnt[N];
int ans;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=5;j++){
			if(s[i][j]=='Y')cnt[j]++;
		}
	}
	for(int i=1;i<=5;i++)ans=max(ans,cnt[i]);
	bool flag=0;
	for(int i=1;i<=5;i++){
		if(cnt[i]==ans){
			if(flag)putchar(',');
			printf("%d",i);
			flag=1;
		}
	}
}

