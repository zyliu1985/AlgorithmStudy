#include<bits/stdc++.h>
using namespace std;

const int N=3010;
int n,m;
int a[N],b[N];
int ans;

void xuan(int x,bool flag,int now){
	if(x>n) {
		ans=max(ans,now);
		return;
	}
	if(flag) {
		xuan(x+1,0,now+a[x]);
		xuan(x+1,1,now);
	}else{
		xuan(x+1,1,now);
	}
}

void subtask0(){
    xuan(1,1,0);
    cout<<ans;
}


	int c[N];
void xuan1(int x,bool flag,int now){
	if(x>n+1) {
		ans=max(ans,now);
		return;
	}
	if(flag) {
		xuan1(x+1,0,now+c[x]);
		xuan1(x+1,1,now);
	}
	else{
		xuan1(x+1,1,now);
	}
}
void subtask1(){

	for(int i=1;i<=n;i++){
		for(int j=0;j<=n+1;j++) c[j]=0;
		for(int j=1;j<i;j++) c[j]=a[j];
		c[i]=b[1];
		for(int j=i+1;j<=n+1;j++) c[j]=a[j-1];
		xuan1(1,1,0);
	}
    cout<<ans;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m==0) subtask0();
	if(m==1) subtask1();
	return 0;
}
