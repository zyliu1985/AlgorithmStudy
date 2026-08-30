#include<bits/stdc++.h>
using namespace std;
int g,p,ret,al[100010],cnt[100010];
int main(){
	scanf("%d%d",&g,&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&al[i]);
	}for(int i=1;i<=p;i++){
		if(cnt[al[i]]==0){
			cnt[al[i]]=1;
			ret++;
		}else{
			int flag=0;
			for(int j=al[i]-1;j>=1;j--){
				if(cnt[j]==0){
					cnt[j]=1;
					ret++;
					flag=1;
					break;
				}
			}if(flag==0){
				break;
			}
		}
	}printf("%d",ret);
	return 0;
} 
