#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,sum=-10,ans[5],len=0;
struct att{
	string sch;
}a[MAXN];
int check(int h){
	int m=0;
	for(int i=0;i<n;i++)	if(a[i].sch[h]=='Y')	m++;
	return m;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i].sch;
	for(int i=0;i<5;i++){
		int k=check(i);
		if(sum==k){
			len++;
			ans[len]=i+1;
		}
		if(sum<k){
			sum=k;
			ans[0]=i+1;
			len=0;
		}
	}
	for(int i=0;i<len;i++)	cout<<ans[i]<<",";
	cout<<ans[len];
	return 0;
}
