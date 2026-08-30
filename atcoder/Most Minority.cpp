#include <iostream>
#include <algorithm>
using namespace std;

string s[105];
int score[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++){
		int num0, num1;
		num0 = num1 = 0;
		for (int j = 1; j <= n; j++)
			if (s[j][i] == '0') num0++;
			else num1++;
		if (num0 < num1){
			for (int j = 1; j <= n; j++)
				if (s[j][i] == '0') score[j]++;
		} else {
			for (int j = 1; j <= n; j++)
				if (s[j][i] == '1') score[j]++;
		}
	}
	int maxs = 0;
	for (int i = 1; i <= n; i++)
		maxs = max(maxs, score[i]);
	for (int i = 1; i <= n; i++)
		if (maxs == score[i])
			cout << i << ' ';
	return 0;
}

