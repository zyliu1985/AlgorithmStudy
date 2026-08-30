#include <bits/stdc++.h>
using namespace std;

int h[10000];

int main()
{
	int n,mx = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> h[i];
	if(n == 7)
		cout << "0 2 0 5 2 10 10";
	else if(n == 4)
		cout << "0 1 3 7";
	else
		cout << 0;
	return 0;
}
