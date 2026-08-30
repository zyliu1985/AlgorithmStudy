#include<bits/stdc++.h>
using namespace std;
int n,h[5003],ans[5003];
struct NODE{int len,l,r,v;};
queue<NODE> que;
int main(){
    cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i]; 
	for(int i=1;i<=n;i++)
		que.push((NODE){1,i,i,0});  //长度1 
	for(int i=1;i<n;i++)
		que.push((NODE){2,i,i+1,abs(h[i]-h[i+1])}); //长度2 
	memset(ans,0x3f,sizeof(ans));
	while(!que.empty()){
		NODE nod=que.front();que.pop();
		ans[nod.len]=min(ans[nod.len],nod.v);  //长度为len时的最小对称值 
		//在长度为len的序列上，左右各加一个形成长度为len+2的序列，对称值增加abs(h[left-1]-h[right+1]) 
		if(nod.l>1&&nod.r<n)que.push((NODE){nod.len+2,nod.l-1,nod.r+1,nod.v+abs(h[nod.l-1]-h[nod.r+1])});   
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";		
    return 0;
} 
/*
# P9325 2023S2 思维 队列

思维 队列 

在长度为len的序列上，左右各加一个形成长度为len+2的序列，对称值增加abs(h[left-1]-h[right+1]) 

使用队列按照长度的顺序处理：长度为len的序列出队，长度为len+2的序列入队 

*/

