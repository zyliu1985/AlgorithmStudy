#include <iostream>
#include <string>
using namespace std;

string mp[105];
int main(){
	int n, m;
	cin >> n >> m;
//	cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i++){
		cin >> mp[i];
		mp[i] = " " + mp[i];
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			cout << mp[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == '*') cout << '*';
			else{
				int cnt = 0;
				for (int x = i-1; x <= i+1; x++)
					for (int y = j-1; y <= j+1; y++)
						if (mp[x][y] == '*') cnt++;
				cout << cnt;
			}
		cout << endl;
	}
	return 0;
}
