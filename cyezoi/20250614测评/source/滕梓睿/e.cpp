#include<bits/stdc++.h>
using namespace std;
int k,n,m;
int c[2001][2001];
int d[2001];
int dj(int a,int b){
	priority_queue <int> q;
	q.push(a);
	int ans=0;
	d[a]=a;
	while(!q.empty()){
		int x=q.top();
		q.pop();
		if(x==b){
			for(int i=x;d[i]!=i;i=d[i]){
				ans+=c[i][d[i]];
			}
			return ans;
		}
		for(int i=1;i<=n;i++){
			if(i!=x&&c[i][x]!=0&&d[i]==0){
				q.push(i);
				d[i]=x;
			}
		}
	} 
	return -1;
}
int main(){
	cin>>k>>n>>m;
	if(k!=1){
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=m;i++){
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		if(h==0){
			c[a][b]=t;
			c[b][a]=t;
		}
	}
	int A,B;
	cin>>A>>B;
	cout<<dj(A,B);
	return 0;
}
