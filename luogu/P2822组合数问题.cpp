#include <iostream>
using namespace std;

int f[2005][2005], s[2005][2005];
int main(){
	cin.tie(0);
	cout.tie(0);
	int t, k;
	cin >> t >> k;
	for (int i = 0; i <= 2000; i++){
		f[i][0] = 1, f[i][i] = 1;
		for (int j = 1; j < i; j++){
			f[i][j] = (f[i-1][j] + f[i-1][j-1]) % k;
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (f[i][j] == 0);
		}
		s[i][i] = s[i-1][i] + s[i][i-1] + s[i][i];
	}
	while (t--){
		int n, m;
		cin >> n >> m;
		cout << s[n][min(m, n)] << endl;
	}
	return 0;
}