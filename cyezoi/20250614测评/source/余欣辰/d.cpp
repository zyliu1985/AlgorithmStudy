# include <bits/stdc++.h>
using namespace std;
int g,p,a[100010],ans=0;
bool gf[100010];
int main(){
	cin >> g >> p;
	for (int i=1;i<=p;i++){cin >> a[i];}
	for (int i=1;i<=p;i++){
		bool f=0;
		for (int j=a[i];j>=1;j--){
			if (gf[j]==0){
				ans++;gf[j]=1;
				f=1;break;
			}
		}
		if (f==0){break;}
	}
	cout << ans;
	return 0;
}
