#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	char a[100005][10];
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	int sum=0,maxx=-0x3f3f3f3f,ans;
	for(int j=1;j<=5;j++){
		sum=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]=='Y')
				sum++;
		}
		if(sum>maxx){
			maxx=sum;
			ans=j;
		}		
	}	
	cout<<ans;
	return 0;
}
