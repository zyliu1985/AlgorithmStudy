#include<bits/stdc++.h>
using namespace std;
int n,mx,tmp,cnt[10];
char s[100010][10];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}for(int i=1;i<=5;i++){
		for(int j=1;j<=n;j++){
			if(s[j][i]=='Y'){
				cnt[i]++;
			}
		}mx=max(mx,cnt[i]);
	}for(int i=1;i<=5;i++){
		if(cnt[i]==mx){
			tmp++;
			if(tmp==1){
				printf("%d",i);
			}else{
				printf(",%d",i);
			}
		}
	}return 0;
} 
