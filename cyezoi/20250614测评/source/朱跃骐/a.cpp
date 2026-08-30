#include<bits/stdc++.h>
using namespace std;
int n;
char c;
struct node{
	int n,id;
}a[10],mx;
bool cmp(node x,node y){
	return x.n>y.n;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			a[j].id=j;
			cin>>c;
			if(c=='Y') a[j].n++;
		}
	}
	sort(a+1,a+6,cmp);
	mx=a[1];
	printf("%d",mx.id);
	for(int i=2;a[i].n==mx.n;i++){
		printf(",%d",a[i].id);
	}
	return 0;
}
