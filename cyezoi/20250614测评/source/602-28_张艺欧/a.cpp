#include<bits/stdc++.h>
using namespace std;
int n, mx, tot, cnt[5];
string a[100010];
int main(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		for(int j=0; j<a[i].size(); ++j){
			if(a[i][j] == 'Y') cnt[j+1]++;
		}
	}
	for(int i=1; i<=5; ++i) mx = max(mx, cnt[i]);
	for(int i=1; i<=5; ++i){
		if(cnt[i] == mx){
			if(tot) cout << ',';
			tot++;
			printf("%d", i);
		}
	}
	return 0;
}
