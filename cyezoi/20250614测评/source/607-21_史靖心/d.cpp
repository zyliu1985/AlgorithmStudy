#include<bits/stdc++.h>
#define lb(x) (x&(-x))
using namespace std;
int a[100010],t[100010],g,p;
int query(int k){
	int ans=0;
	while(k)ans+=t[k],k-=lb(k);
	return ans;
}
void update(int k){
	while(k<=g)t[k]++,k+=lb(k);
}
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		int k;
		cin>>k;
		if(query(k)==k){
			cout<<i-1;
			return 0;
		}
		update(k);
	}
	cout<<p;
	return 0;
}
