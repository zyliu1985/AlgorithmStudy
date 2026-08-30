#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,cnt[6],mx;
char c;
vector<int> v(1);
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y')cnt[j]++;
		}
	for(int i=1;i<=5;i++)mx=max(mx,cnt[i]);
	for(int i=1;i<=5;i++)if(cnt[i]==mx)v.push_back(i);
	cout<<v[1];
	for(int i=2;i<(int)v.size();i++)cout<<","<<v[i];
	return 0;
}
