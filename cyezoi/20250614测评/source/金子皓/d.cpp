#include <bits/stdc++.h>
using namespace std;

int g,p,gs[100100];
bool parked[100100];
int main()
{
	cin>>g>>p;
	for(int i=0;i<p;i++) cin>>gs[i];
	
	for(int i=0;i<p;i++)
	{
		bool yes=false;
		for(int j=gs[i];j>0 && !yes;j--) if(!parked[j]) parked[j]=yes=true;
		if(!yes)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<p;
	return 0;
}
