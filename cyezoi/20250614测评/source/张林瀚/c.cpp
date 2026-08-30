#include <iostream>
#include <cstring>

using namespace std;

int n, a[5010], s[5010][5010]; //s[i][j] : 以下标i开头的长度为j的值 
int ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			s[j][i] = s[j + 1][i - 2] + abs(a[j] - a[j + i - 1]);
		}
	}
	for (int j = 1; j <= n; j++) {
		int minn = 1e9;
		for (int i = 1; i <= n - j + 1; i++)
			minn = min(minn, s[i][j]);
		cout << minn << " ";
	}
	cout << "\n";
	return 0;
}
