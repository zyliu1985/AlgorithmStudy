#include<bits/stdc++.h>
using namespace std;

	int n,b[5];
	char a[100010][6];
	
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= 5;j++){
			cin >> a[i][j];
			if (a[i][j] == 'Y'){
				b[j]++;
			}
		}
	}
	int mx = -1;
	for (int i = 1;i <= 5;i++){
		if (b[i] > mx){
			mx = b[i];
		}
	}
	bool j = 0;
	for (int i = 1;i <= 5;i++){
		if (b[i] == mx){
			if (j == 1)
				cout << ',';
			j = 1;
			cout << i;
		}
	}
	return 0;
}

