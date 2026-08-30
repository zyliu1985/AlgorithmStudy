#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int g,p,i;
//int get_sum = 0;//统计总消耗 
struct port{
	int to_free;
	bool taken;
} a[N];
int n_t_cg[N];
void dfs(int x,int cnt){
	if(!a[x].taken){
		for(int j = 1;j <= cnt;j++)
			a[n_t_cg[j]].to_free = x;
		a[x].taken = 1;
		//get_sum+=cnt;
		return;
	}
	if(a[x].taken){
		//get_sum++;
		if(a[x].to_free <= 0){
			//printf("%d\n",get_sum);
			printf("%d\n",i-1);
			exit(0);
		}
		cnt++;
		n_t_cg[cnt] = x;
		dfs(a[x].to_free,cnt);
	}
	return;
}
int main(){
	scanf("%d %d",&g,&p);
	for(i = 1;i <= g;i++)
		a[i].to_free = i-1;
	
	
	for(i = 1;i <= p;i++){
		int x;
		scanf("%d",&x);
		if(!a[x].taken) a[x].taken = 1;
		else{
			dfs(x,0);
		}
	}
	//printf("圆满结束：%d\n",get_sum);
	printf("%d\n",p);
	return 0;
}
