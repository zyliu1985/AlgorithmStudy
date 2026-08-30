#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

bool vis[N];
int g, p;
set <int> st;

void solve1()
{
	for (int i = 1; i <= p; i++)
	{
		int r;
		bool f = false;
		cin >> r;
		for (int j = r; j >= 1; j--)
			if (!vis[j])	
			{
				f = true;
				vis[j] = true;
				break;
			}
		if (!f)	
		{
			cout << i - 1 << endl;
			return;
		}
	}
	cout << p << endl;
}

int main()
{
	cin >> g >> p;
	if (g <= (int)2e3)
	{
		solve1();
		return 0;
	}
	for (int i = 1; i <= g; i++)
		st.insert(i);
	for (int i = 1; i <= p; i++)
	{
		int r;
		cin >> r;
		auto tmp = upper_bound (st.begin(), st.end(), r);
		if (tmp != st.begin())	tmp--;
		int pos = *tmp;
		if (pos > r)	
		{
			cout << i - 1 << endl;
			return 0;
		}
		st.erase(tmp);
	}
	cout << p << endl;
	return 0;
}
