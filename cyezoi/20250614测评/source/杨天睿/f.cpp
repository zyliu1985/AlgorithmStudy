#include<bits/stdc++.h>
using namespace std;
int n,m,a[4005],x;
bool flag[3005];
struct Node{
	int a,id;
}b[3005];
bool cmp2(Node x,Node y){
	return x.a>y.a;
}
bool cmp(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	if(m==0){
		for(int i=1;i<=n;++i){
			b[i].a=a[i];
			b[i].id=i;
		}
		sort(b+1,b+n+1,cmp2);
		long long sum=0;
		for(int i=1;i<=n;++i)
			if(!flag[b[i].id-1]&&!flag[b[i].id+1]){
				flag[b[i].id]=1;
				sum+=b[i].a;
			}
		cout<<sum;
	}
	else{
		for(int i=1;i<=m;++i)
			cin>>a[n+i];
		sort(a+1,a+n+m+1,cmp);
		long long sum=0;
		for(int i=1;i<=(n+m+1)/2;++i)
			sum+=a[i];
		cout<<sum;
	}
	return 0;
}

