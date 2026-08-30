#include<bits/stdc++.h>
using namespace std;
int a[10][200010];
//a[1]:第一行顶部
//a[2]:第一行左侧
//a[3]:两行之间 
//a[4]:第二行左侧
//a[5]:第二行底部 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	char c;
	string s1="?",s2="?";
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c;
		s1+=c;
	}
	for(int i=1;i<=n;++i){
		cin>>c;
		s2+=c;
	}
	for(int i=1;i<s1.size();++i){
		if(s1[i]=='1'){
			a[2][i]++;
			a[2][i+1]++;
			if(i%2){
				a[3][i]++;
			}
			else a[1][i]++;
		}
	}
	for(int i=1;i<s2.size();++i){
		if(s2[i]=='1'){
			a[4][i]++;
			a[4][i+1]++;
			if(i%2){
				a[3][i]++;
			}
			else a[5][i]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=5;++i)
		for(int j=1;j<=n+1;++j)
			if(a[i][j]==1)
				cnt++;
	cout<<cnt;
	return 0;
}

