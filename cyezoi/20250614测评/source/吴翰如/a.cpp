#include <bits/stdc++.h>
using namespace std;

const int N=100010;

int n,maxx,maxt,cnt,a[N],ans[N];
char c;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j){
			cin >> c;
			if(c=='Y')
				++a[j];
			maxx=max(maxx,a[j]);
		}
	}
	
	for(int i=1;i<=5;++i)
		if(a[i]==maxx)
			ans[++cnt]=i;
	
	for(int i=1;i<cnt;++i)
		printf("%d,",ans[i]);
	printf("%d",ans[cnt]);
	return 0;
}


