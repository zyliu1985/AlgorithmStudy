#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int g,p,park[N],ans;
bool op[N],air[N];

int main()
{
	cin>>g>>p;
	for(int i=1;i<=p;i++) cin>>park[i];
	for(int i=1;i<=p;i++){
		for(int j=park[i];j>=1;j--){
			if(!op[j]&&!air[i]){
				op[j]=1;
				air[i]=1;
				ans++;
			}
		}
		if(air[i]==0) break;
	}
	cout<<ans;
	return 0;
} 
