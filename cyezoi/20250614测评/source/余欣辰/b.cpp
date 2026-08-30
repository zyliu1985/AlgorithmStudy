# include <bits/stdc++.h>
using namespace std;
int c,ans=0;
bool a[10][200010];
int main(){
	cin >> c;
	for (int i=1;i<=c;i++){
		cin >> a[1][i];
		if (a[1][i]){ans+=3;}
	}
	for (int i=1;i<=c;i++){
		cin >> a[2][i];
		if (a[2][i]){ans+=3;}
	}
	for (int i=1;i<=c;i++){
		if (a[1][i]==0){continue;}
		if (a[1][i+1]){ans-=2;}
		if (i%2==1){if (a[2][i]){ans-=2;}}
	}
	for (int i=1;i<=c;i++){
		if (a[2][i]==0){continue;}
		if (a[2][i+1]){ans-=2;}
	}
	cout << ans;
	return 0;
}
