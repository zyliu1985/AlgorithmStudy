#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double st[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	st[0] = (s[0] == 't');
	for (int i = 1; i < s.size(); i++)
		st[i] = st[i-1] + (s[i] == 't');
	double ans = 0;
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 2; j < s.size(); j++)
			if (s[i] == 't' && s[j] == 't')
				ans = max(ans, (st[j] - (i == 0 ? 0 : st[i-1]) - 2) / (j - i - 1));
	printf("%.12lf", ans);
	return 0;
}

