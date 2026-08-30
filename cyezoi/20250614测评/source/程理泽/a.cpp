#include<iostream>
#include<vector>
using namespace std;
vector<int>a[100002];
int b[6];

int main()
{
	int n,max = 0;
	char c;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			cin >> c;
			if (c == 'Y') b[j]++;
		}
	}
	for (int i = 0;i < 5;i++)
	{
		if (b[i] > b[max])
		{
			max = i;
			a[b[max]].push_back(i);
		}
		else if (b[i] == b[max]) a[b[max]].push_back(i);
	}
	for (int i = 0;i < a[b[max]].size();i++)
	{
		cout << a[b[max]][i]+1;
		if (i < a[b[max]].size()-1) cout << ',';
	}
	return 0;
}
