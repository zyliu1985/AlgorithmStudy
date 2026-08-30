//B;
#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int ans=0;
int cur=0;
int main(){
	int c;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=1;i<=c;i++){
		cin>>b[i];
		ans+=b[i];
	}
	ans*=3;
	for(int j=1;j<=c;j++){
		if(a[j]==0)continue;
		else{
			if(a[j-1]!=0){
				a[j]=a[j-1];
			}
			else{
				cur++;
				a[j]=cur;
			}
		}
	}
	for(int j=1;j<=c;j++){
		if(b[j]==0)continue;
		else{
			if(b[j-1]!=0){
				b[j]=b[j-1];
			}
			else if(a[j]!=0){
				b[j]=a[j];
			}
			else{
				cur++;
				b[j]=cur;
			}
		}
	}
	int m[cur+1];
	memset(m,0,sizeof(m));
	for(int i=1;i<=c;i++){
		if(a[i]!=0)m[a[i]]++;
	}
	for(int i=1;i<=c;i++){
		if(b[i]!=0)m[b[i]]++;
	}
	for(int i=1;i<=cur;i++){
		ans-=(m[i]-1)*2;
	}
	cout<<ans<<"\n";
	/*
	for(int i=1;i<=c;i++)cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=c;i++)cout<<b[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=cur;i++)cout<<m[i]<<" ";
	*/
	return 0;
}
