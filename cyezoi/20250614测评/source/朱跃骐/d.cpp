#include<bits/stdc++.h>
using namespace std;
int g,p,x;
bool b[100005],flag;
int main(){
	scanf("%d%d",&g,&p);
	for(int i=1;i<=p;i++){
		flag=0;
		scanf("%d",&x);
		for(int j=x;j>=1;j--){
			if(!b[j]){
				b[j]=1,flag=1;
				break;
			}
		}
		if(!flag){
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",p);
	return 0;
}
