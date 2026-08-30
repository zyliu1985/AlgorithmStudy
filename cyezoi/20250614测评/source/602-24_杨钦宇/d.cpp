#include<bits/stdc++.h>
using namespace std;
int G,P,g[100001],m[100001],ans;
int main(){
	//freopen("d.in","r",stdin);
	cin>>G>>P;
	for(int i=1;i<=P;i++)cin>>g[i];
	for(int i=1;i<=G;i++)m[i]=i;
	for(int i=1;i<=P;i++){
		stack<int>s;
		while(m[g[i]]!=g[i]){
			s.push(g[i]);
			g[i]=m[g[i]];
		}
		if(g[i]==0){
			cout<<ans;
			return 0;
		}
		ans++;
		m[g[i]]=g[i]-1;
		while(!s.empty()){
			m[s.top()]=g[i]-1;
			s.pop(); 
		} 
	}
	cout<<ans;
	return 0;
}

