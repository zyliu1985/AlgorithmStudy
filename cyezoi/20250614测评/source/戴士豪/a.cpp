#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int q;
}a[10];
int n,cnt=1;
char c;

bool cmp(node x,node y){
	if(x.x==y.x){
		return x.q<y.q;
	}
	return x.x>y.x;
}

int main(){
	cin>>n;
	for(int j=1;j<=5;j++){
		a[j].x=0;
		a[j].q=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y'){
				a[j].x++;
			}
		}
	}
	sort(a+1,a+5+1,cmp);
	for(int j=2;j<=5;j++){
		if(a[j].x==a[j-1].x){
			cnt++;
		}
		else{
			break;
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i].q;
		if(i<cnt){
			cout<<",";
		}
	}
	return 0;
}
