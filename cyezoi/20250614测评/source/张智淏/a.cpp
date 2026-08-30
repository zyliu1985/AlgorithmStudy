#include<bits/stdc++.h>
using namespace std;
int n,a[6],maxn;
bool b[100005][6],f;
char c;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		c=getchar();
		for(int j=1;j<=5;j++){
			c=getchar();
			if(c=='Y')b[i][j]=1;
		}
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=n;j++){
			a[i]+=b[j][i];
		}
	}
	for(int i=1;i<=5;i++){
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=5;i++){
		if(a[i]==maxn){
			if(f)printf(",");
			f=1;
			printf("%d",i);
		}	
	}
	return 0;
}
