#include<bits/stdc++.h>
using namespace std;
int n,mounts[500005];
int s1[500005],s2[500005],a1,a2;
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	cin>>n>>mounts[1];
	for(int i=2;i<=n;i++){
		cin>>mounts[i];
	}
	for(int i=1;i<=n;i++){
		int minn=2147483647;
		for(int j=1;j<=n-i+1;j++){
			int sum=0;
			if((i+1)/2>=2 and i%2==0) {
				s2[j]=abs(mounts[j]-mounts[j+i-1])+abs(s2[j+1]);
				
				if(s2[j]<minn) minn=s2[j];
			}else if((i+1)/2>=2 and i%2==1) {
				s1[j]=abs(mounts[j]-mounts[j+i-1])+abs(s1[j+1]);
			//	cout<<abs(s1[j+1])<<"kkk"<<" ";
				if(s1[j]<minn) minn=s1[j];
			}else if(i%2==1){
				minn=0;
			}else if(i%2==0){
				s2[j]=abs(mounts[j]-mounts[j+1]);
				if(s2[j]<minn) minn=s2[j];
			}
		}
		cout<<minn<<" ";
	}
	return 0;
}
