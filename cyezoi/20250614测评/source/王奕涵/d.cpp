#include<bits/stdc++.h>
using namespace std;
int g,p,cnt,m,mm=-1;
int gg[100005];
bool ggg[100005]={0};
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>gg[i];
		if(gg[i]>m){
			m=gg[i];
			mm=i;
		}
		for(int j=gg[i];j>=1;j--){
			if(ggg[j]==0){
				ggg[j]=1;
				cnt++;
				gg[i]=-1;
				break;
			}
		}
		if(gg[i]!=-1)break;
	}
	memset(ggg,0,sizeof ggg);
	memset(gg,0,sizeof gg);
	int cntt=0;
	for(int i=mm;i<=p;i++){
			for(int j=gg[i];j>=1;j--){
			if(ggg[j]==0){
				ggg[j]=1;
				cntt++;
				gg[i]=-1;
				break;
			}
		}
		if(gg[i]!=-1)break;
	}
	cout<<max(cnt,cntt);
}
