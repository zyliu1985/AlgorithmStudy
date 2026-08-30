#include<bits/stdc++.h>
int G,P;
bool a[100001];
int main(){
	scanf("%d%d",&G,&P);
	for(int i=1,g,id;i<=P;i++){
		scanf("%d",&g);
		for(id=g;id>=1&&a[id];id--);
		if(!id){
			printf("%d",i-1);
			return 0;
		}
		a[id]=1;
	}
	printf("%d",P);
	return 0;
}
