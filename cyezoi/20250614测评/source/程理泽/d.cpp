#include<iostream>
using namespace std;

bool G[100002];
int main()
{
	int g,p,num = 0,t;
	cin >> t >> p;
	for (int i = 0;i < p;i++)
	{
		cin >> g;
		int j = g;
		while (G[j] && j != 0) j--;
		if (j == 0) break;
		num++;
		G[j] = 1;
	}
	cout << num;
	return 0;
}
