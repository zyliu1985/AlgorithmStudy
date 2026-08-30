#include<bits/stdc++.h>
using namespace std;

int n;

struct node{
	int cnt,day;
}ans[100005];

bool cmp(node a,node b)
{
	if(a.cnt==b.cnt) return a.day<b.day;
	else return a.cnt>b.cnt;
}

int main()
{
	cin>>n;
	for(int i=1;i<=5;i++) ans[i].day=i;
	for(int i=1;i<=n;i++){
		char s[5];
		for(int j=0;j<5;j++) cin>>s[j];
		for(int j=1;j<=5;j++)
			if(s[j-1]=='Y') ans[j].cnt++;
	}
	sort(ans+1,ans+6,cmp);
	cout<<ans[1].day;
	for(int i=2;i<=n;i++)
		if(ans[i].cnt==ans[1].cnt) cout<<","<<ans[i].day;
	return 0;
}
