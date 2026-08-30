//100pts * 100% = 100pts
#include <bits/stdc++.h>
using namespace std;
int n;
string str[100005];
int ok[8];
int mx = -1;
vector<int> v;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> str[i];
	for(int i = 0; i < 5; i++)
	{
		for(int k = 1; k <= n; k++)
			if(str[k][i] == 'Y')
				ok[i + 1]++;
		mx = max(mx, ok[i + 1]);
	}
	for(int i = 1; i <= 5; i++)
		if(ok[i] == mx)
			v.push_back(i);
	if(v.size() > 1)
		for(int i = 0; i < v.size() - 1; i++)
			cout << v[i] << ",";
	if(v.size())
		cout << v[v.size() - 1];
	return 0;
}
/*
5
YY..Y
.YY.Y
.Y.Y.Y
.YY.Y
Y...Y
*/
