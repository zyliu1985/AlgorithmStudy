#include<bits/stdc++.h>
using namespace std;
string s[100009];
struct int2{
	int a;
	int b;
}cnt[5];
bool cmp(int2 a2,int2 b2){
	return a2.a=b2.a&&a2.b<b2.b;
}
int main(){
	int n=0;
	cin>>n;
	for(int i=1;i<=5;i++){
		cnt[i].b=i;
		cnt[i].a=0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			if(s[i][j]=='Y')
			cnt[j+1].a++;
		}
	}
	int ans=0;
	for(int i=1;i<=5;i++){
		ans=max(ans,cnt[i].a);
	}
	sort(cnt+1,cnt+6,cmp);
	int len=0;
	for(int i=1;i<=5;i++){
		if(cnt[i].a==ans){
			cout<<i;
			len=i;
			break;
		}
	}
	for(int i=len+1;i<6;i++){
		if(cnt[i].a==ans){
			cout<<','<<i;
		}
	}
	return 0;
}
