#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int g, p, a[100006];
bool isHave[100006];
bool couldgoing = 1;
int main()
{
	cin >> g >> p;
	for(int i = 1; i <= p; i++) cin >> a[i];
	for(int i = 1; i <= p; i++)
	{
		couldgoing = 0;
		for(int j = a[i]; j >= 1; j--)
		{
			if(!isHave[j])
			{
				isHave[j] = true;
				couldgoing = 1;
				break;
			}
		}
		if(!couldgoing)
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << p << endl;
	return 0;
}
