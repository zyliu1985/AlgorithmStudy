#include<bits/stdc++.h>
using namespace std;

	int n,a[4][200010],num = 0;
	
int main(){
	cin >> n;
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	a[1][0] = 0;
	a[1][n + 1] = 0;
	a[2][0] = 0;
	a[2][n + 1] = 0;
	for (int i = 1;i <= n;i++){
		if (a[1][i] == 1){
			num += 3;
			if (a[1][i - 1] == 1)
				num--;
			if (a[1][i + 1] == 1)
				num--;
			if (i % 2 == 1 && a[2][i] == 1)
				num--;
		}
	}
	for (int i = 1;i <= n;i++){
		if (a[2][i] == 1){
			num += 3;
			if (a[2][i - 1] == 1)
				num--;
			if (a[2][i + 1] == 1)
				num--;
			if (i % 2 == 1 && a[1][i] == 1)
				num--;
		}
	}
	cout << num;
	return 0;
}

