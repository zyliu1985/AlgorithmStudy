#include <bits/stdc++.h>
using namespace std;
int n;
string s[100009];
int cnt[10];

int main (){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 0;j < 5;j++){
			if(s[i][j] == 'Y'){
				cnt[j+1]++;
			}
		}
	}
	int k = 0;
	for (int i = 1;i <= 5;i++){
		if(cnt[i] > k){
			k = cnt[i];
		}
	}
	int m = 0;
	for (int i = 1;i <= 5;i++){
		if(k == cnt[i]){
			m++;
		}
	}
	for (int i = 1;i <= 5;i++){
		if(k == cnt[i]){
			if(m == 1){
				cout << i;
			}else{
				cout << i << ',';
				m--;
			}
		}
	}
	return 0;
}
