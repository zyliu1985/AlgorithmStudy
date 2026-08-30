#include<bits/stdc++.h>
using namespace std;
int C,a[3][200001],ans;
int main(){
	//freopen("b.in","r",stdin);
	//freopen("b.ans","w",stdout);
	cin>>C;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=C;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=C;j++){
			if(a[i][j]){
				if(a[i][j-1])ans++;
				else ans+=3;
			}
		}
	}
	for(int i=1;i<=C;i++){
		if(a[1][i]&&a[2][i]&&i%2==1)ans-=2;
	}
	cout<<ans<<endl;
	return 0;
}

