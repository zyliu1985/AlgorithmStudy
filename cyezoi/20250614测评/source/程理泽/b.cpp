#include<iostream>
using namespace std;

bool a[200002];
bool b[200002];
int main()
{
	int c,num = 0,zk = 0;
	cin >> c;
	for (int i = 1;i <= c;i++) 
	{
		cin >> a[i];
		if (!a[i]) continue;
		num += 3;
		zk += a[i-1];
	}
	for (int i = 1;i <= c;i++) 
	{
		cin >> b[i];
		if (!b[i]) continue;
		num += 3;
		zk += b[i-1];
		zk += (i%2)*a[i];
	}
	cout << num-2*zk;
	return 0;
}
