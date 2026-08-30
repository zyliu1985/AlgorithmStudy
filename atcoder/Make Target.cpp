#include <iostream>
using namespace std;

bool mp[55][55];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= (n + 1) / 2; i++)
		for (int j = i; j <= n - i + 1; j++)
			for (int k = i; k <= n - i + 1; k++)
				mp[j][k] ^= 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (mp[i][j]) cout << '#';
			else cout << '.';
		cout << '\n';
	}
	return 0;
}


