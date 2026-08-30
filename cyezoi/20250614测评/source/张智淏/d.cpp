#include<bits/stdc++.h>
using namespace std;
int g,p,a[100005],t;
bool b[100005];
int main(){
	scanf("%d%d",&g,&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=p;i++){
		t=a[i];
		while(t!=0){
			if(b[t]==0){
				b[t]=1;
				break;
			}
			t--;
		}
		if(t==0){
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",p);
	return 0;
}
