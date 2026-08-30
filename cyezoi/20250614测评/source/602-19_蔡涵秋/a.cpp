#include <bits/stdc++.h>
using namespace std;

vector <int> ans;
int n, maxn, box[10];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		s = " " + s;
		for (int j = 1; j <= 5; j++)
			if (s[j] == 'Y')	box[j]++;
	}
	for (int i = 1; i <= 5; i++)
		maxn = max(maxn, box[i]);
	for (int i = 1; i <= 5; i++)
		if (box[i] == maxn)	ans.push_back(i);
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << "," << ans[i];
	cout << endl;
	return 0;
}
