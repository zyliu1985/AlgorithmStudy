#include<bits/stdc++.h>
using namespace std;
int M[105],N[3005],NM[3105],nm[3][3105],maxlen=0,k;
int n,m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>M[i];
	}
	if(m==0){
		for(int i=1;i<=n+m;i++){
			nm[1][i]=nm[2][i-1]+N[i];
			nm[2][i]=max(nm[2][i-1],nm[1][i-1]);
		}
		cout<<max(nm[1][n+m],nm[2][n+m]);
		return 0;
	}
	if(m==1){
		for(int j=1;j<=n+m;j++){
			k=1;
			for(int i=1;i<=m+n;i++){
				if(i!=j){
					NM[i]=N[k];
				}
				else{
					NM[i]=M[1],k--;
				}
				k++;
			}
			for(int i=1;i<=n+m;i++){
				nm[1][i]=nm[2][i-1]+NM[i];
				nm[2][i]=max(nm[2][i-1],nm[1][i-1]);
			}
			maxlen=max(maxlen,nm[2][n+m]);
			maxlen=max(maxlen,nm[1][n+m]);
		}
	}
	cout<<maxlen;
	return 0;
}
