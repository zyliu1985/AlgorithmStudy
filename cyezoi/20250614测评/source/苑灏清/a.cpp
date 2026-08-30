#include<bits/stdc++.h>
using namespace std;

int n;

struct k
{
	long long s;
	int wz;
}a[6];

bool cmp(k x, k y)
{
	return x.s > y.s;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char k;
			cin >> k;
			if (k == 'Y') a[j].s++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		a[i].wz = i + 1;
	}
	sort(a, a + 5, cmp);
	
	long long mx = a[0].s, i = 1;
	cout << a[0].wz;
	while (mx == a[i].s)
	{
		cout << "," << a[i].wz;
		i++;
	}
	return 0;
	
}
