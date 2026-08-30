#include<bits/stdc++.h>
using namespace std;
int n,ans[6],maxn;
string s[100001];
queue<int>q;
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=0;i<5;i++){
		for(int j=1;j<=n;j++){
			if(s[j][i]=='Y'){
				ans[i+1]++;
			}
		}
		maxn=max(maxn,ans[i+1]);
	}
	for(int i=1;i<=5;i++){
		if(ans[i]==maxn){
			q.push(i);
		}
	}
	while(true){
		cout<<q.front();
		q.pop();
		if(q.empty()){
			break;
		}else{
			cout<<",";
		}
	}
	return 0;
}

