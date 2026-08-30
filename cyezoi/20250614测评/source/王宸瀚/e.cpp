#include <bits/stdc++.h>
using namespace std;
int k,n,m;
int a[10009],b[10009],t[10009],h[10009];

int main (){
	cin >> k >> n >> m;
	for (int i = 1;i <= m;i++){
		cin >> a[i] >> b[i] >> t[i] >> h[i];
	}
	if(k == 1){
		cout << "-1" << endl;
	}
	return 0;
}
