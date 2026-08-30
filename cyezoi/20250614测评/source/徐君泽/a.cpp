#include<bits/stdc++.h>
using namespace std;

int n;
int day[5];
char a[100000][5];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
			if(a[i][j]=='Y') day[j]++;
		}
	}
	int maxn=max(day[0],max(day[1],max(day[2],max(day[3],day[4]))));
	bool flag=false;
	for(int i=0;i<5;i++){
		if(day[i]==maxn) {
			if(flag) cout<<",";
			cout<<i+1;
			flag=true;
		}
	}
}
