#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
int c,ans;
bool f[3][200010];
signed main(){
	cin>>c;
	for(int i=1;i<=c;i++)cin>>f[1][i];
	for(int i=1;i<=c;i++)cin>>f[2][i];
	if(c==1){
		if(f[1][1]==1){
			if(f[2][1]==1){
				cout<<4;
				return 0;
			}
			else{
				cout<<3;
				return 0;
			}
		}
		else{
			if(f[2][1]==1){
				cout<<4;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	if(f[1][1]==1){
		ans++;
		if(f[1][2]==0)ans++;
		if(f[2][1]==0)ans++;
	}
	for(int i=2;i<c;i++){//the first line
		if(f[1][i]){
			if(i%2){
				if(f[1][i-1]==0)ans++;
				if(f[1][i+1]==0)ans++;
				if(f[2][i]==0)ans++;
			}
			else{
				ans++;
				if(f[1][i-1]==0)ans++;
				if(f[1][i+1]==0)ans++;
			}
		}
	}
	if(f[1][c]==1){
		ans++;
		if(f[1][c-1]==0)ans++;
		if(f[2][c]==0)ans++;
	}
	if(f[2][1]==1){
		ans++;
		if(f[1][1]==0)ans++;
		if(f[2][2]==0)ans++;
	}
	for(int i=2;i<c;i++){//the second line
		if(f[2][i]){
			if(i%2){
				if(f[2][i-1]==0)ans++;
				if(f[2][i+1]==0)ans++;
				if(f[1][i]==0)ans++;
			}
			else{
				ans++;
				if(f[2][i-1]==0)ans++;
				if(f[2][i+1]==0)ans++;
			}
		}
	}
	if(f[2][c]==1){
		ans++;
		if(f[2][c-1]==0)ans++;
		if(f[1][c]==0)ans++;
	}
	cout<<ans;
	return 0;
}
