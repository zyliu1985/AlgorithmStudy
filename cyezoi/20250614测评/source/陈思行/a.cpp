#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 5; j++){
			char c;
			cin >> c;
			if (c == 'Y') a[j]++;
		}
	}	
	int maxn = 0;
	for (int i = 1; i <= 5; i++){
		maxn = max(maxn, a[i]);
	}
	string s = "";
	for (int i = 1; i <= 5; i++){
		if (a[i] == maxn){
			s += i + '0';
			s += ",";
		}
	}
	cout << s.substr(0, s.size() - 1);
	return 0;
}
