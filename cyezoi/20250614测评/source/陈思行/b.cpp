#include <bits/stdc++.h>
using namespace std;
int c;
int a[201000];
int b[201000];
int ans;
int main(){
	cin >> c;
	for (int i = 1; i <= c; i++){
		cin >> a[i];
		if (a[i] == 1) ans += 3; 
	}
	for (int i = 1; i <= c; i++){
		cin >> b[i];
		if (b[i] == 1) ans += 3; 
	}	
	for (int i = 1; i <= c; i++){
		if (a[i] == a[i + 1] && a[i] == 1) ans -= 2;
		if (b[i] == b[i + 1] && b[i] == 1) ans -= 2;
		if (a[i] == b[i] && a[i] == 1) ans -= 2;
	}
	cout << ans;
	return 0;
}
