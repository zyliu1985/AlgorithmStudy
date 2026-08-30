#include <iostream>
using namespace std;

char c[15], t[15];
int x[15];
bool vis[15];
string mp[15][15];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int line = 2; line <= n; line++)
		for (int i = 1; i <= n; i++){
			string s;
			cin >> s;
			mp[line][i] = s;
			if (i == 1) continue;
			if (s.size() > 1) x[line]++;
		}
	for (int i = 2; i <= n; i++){
		if (vis[x[i]] || x[i] > n-1){cout << "ERROR!" << endl; return 0;}
		vis[x[i]] = true;
		t[x[i]] = c[i];
	}
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++){
			int num = x[i] + x[j];
			if (num / (n-1) > 0){
				if (mp[i][j].size() != 2){cout << "ERROR!" << endl; return 0;}
				if (t[num % (n-1)] != mp[i][j][1]){cout << "ERROR!" << endl; return 0;}
				if (t[num / (n-1)] != mp[i][j][0]){cout << "ERROR!" << endl; return 0;}
			} else {
				if (mp[i][j].size() != 1){cout << "ERROR!" << endl; return 0;}
				if (t[num] != mp[i][j][0]){cout << "ERROR!" << endl; return 0;}
			}
		}
	for (int i = 2; i <= n; i++)
		cout << c[i] << '=' << x[i] << ' ';
	cout << endl << n - 1 << endl;
	return 0;
}
