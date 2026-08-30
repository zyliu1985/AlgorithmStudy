#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
}cnt[10];
int n,pre;
bool cmp(node x,node y){
	if(x.num!=y.num){
		return x.num>y.num;
	}
	return x.id<y.id;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=5;i++){
		cnt[i].id=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char c;
			scanf(" %c",&c);
			if(c=='Y'){
				cnt[j].num++;
			}
		}
	}
	sort(cnt+1,cnt+5+1,cmp);
	for(int i=1;i<=5;i++){
		if(i==1){
			printf("%d",cnt[i].id);
			pre=cnt[i].num;
			if(cnt[i+1].num==pre){
				printf(",");
			}
			else{
				break;
			}
		}
		else{
			if(cnt[i].num==pre){
				printf("%d",cnt[i].id);
				if(i+1<=5&&cnt[i+1].num==pre){
					printf(",");
				}
			}
			else{
				break;
			}
		}
	}
}
