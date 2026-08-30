//400pts * 40% = 160pts
#include <bits/stdc++.h>
using namespace std;
int G, p, g;
bool used[100005];
int main()
{
	cin >> G >> p;
	for(int t = 1; t <= p; t++)
	{
		cin >> g;
		bool f = 0;
		for(int i = g; i >= 1; i--)
			if(!used[i])
			{
				f = 1;
				used[i] = 1;
				break;
			}
		if(!f)
		{
			cout << t - 1 << endl;
			return 0;
		}
	}
	cout << p << endl;
	return 0;
}
/*
4 3 4 1 1


4 6 2 2 3 3 4 4
*/
