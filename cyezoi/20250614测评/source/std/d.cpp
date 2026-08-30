#include<bits/stdc++.h>
using namespace std;
int g,p,cnt,pos,proot,a[100005];
int f[100005];
void init(int n){
	for(int i=1;i<=n;i++)f[i]=i;
} 
int getroot(int u){
	if(f[u]==u)return u;
	return f[u]=getroot(f[u]);
}
void conn(int u,int v){
	f[getroot(u)]=getroot(v);  //u所在的树，挂在v所在的树下 
}
int main(){
    cin>>g>>p;
	init(g);
	for(int i=1;i<=p;i++){
		cin>>pos;
		//使用pos所在的树根
		proot=getroot(pos); 
		if(proot==0)break;  //无停机坪可用 
		cnt++;
		//并将pos所在的树合并至前方一棵树上
		conn(proot,getroot(proot-1)); 
	}	
	cout<<cnt;
    return 0;
} 
/*
# P9812 2015 S3  贪心 并查集

贪心：每次都用可使用的最大编号

优化：如何快速跳过已经用掉的大编号 ？ 
并查集：已经用过的大编号合并至前方小编号
 
每棵树的树根是可用的停机坪，子节点是不可用的停机坪
 
可使用停机坪 1-pos
尽量用大的编号，即pos的根
树根使用完毕后，将这棵树挂在前方的一棵树下

*/

