#include<bits/stdc++.h>
using namespace std;
int n,p,cnt;
struct node{
    int xu,g;	
}a[100010];
int now[100010];

bool cmp(node x,node y){
	return x.g<y.g;
}

bool cmp2(node x,node y){
	return x.xu<y.xu;
}

int main(){
	cin>>n>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i].g;
		a[i].xu=i;
	}
	sort(a+1,a+1+p,cmp);
	for(int i=1;i<=p;i++){
		int l=i,r=i;
		while(a[++r].g==a[l].g);
		sort(a+l,a+r,cmp2);
		i=r-1;
	}
	for(int i=1;i<=p;i++){
		if(a[i].g>cnt){
			cnt++;
			now[a[i].xu]=1;
		}
	}
	for(int i=1;i<=p;i++){
		if(now[i]==0){
			cout<<i-1;
			return 0;
		}
	}
	cout<<p;
}
