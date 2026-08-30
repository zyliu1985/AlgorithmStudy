#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,a[100010],step=0,cnt=0;
	bool flag=true;
	cin>>n;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	char book[n+2];
	memset(book,true,sizeof(book));
	for(int i=1;i<=m;i++){
		if(book[a[i]]==true){
			book[a[i]]=false;
			step++;
		}
		else{
			flag=false;
			for(int j=a[i];j>=1;j--){
				if(book[j]==true){
					cnt++,step++,book[j]=false;
					break;
				}
			}
		}
		if(flag==false&&cnt==0)
			break;
		flag=true,cnt=0;
	}
	cout<<step;
return 0;
}
