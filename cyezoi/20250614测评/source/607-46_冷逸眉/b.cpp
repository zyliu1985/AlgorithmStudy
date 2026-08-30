#include <iostream>
using namespace std;
int n,c[4][200005];
long long cnt;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> c[1][i];
	for(int i = 1;i <= n;i++)
		cin >> c[2][i];
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= n;j++){
			if(c[i][j] == 0) continue;
			cnt += 3;
			cnt -= (c[i][j + 1] + c[i + 1][j] + c[i][j - 1] + c[i - 1][j]);
		}
	}
	cout << cnt;
	return 0;
}
