#include <bits/stdc++.h>
using namespace std;

struct day
{
	long long daynum,person;
} days[6];

bool cmp(day a,day b)
{
	 if(a.daynum!=b.daynum) return a.person>b.person ;
	 else return a.daynum<b.daynum;
} 

long long n;

int main()
{
	for(long long i=0;i<5;i++)
	{
		days[i].daynum=i+1;
	}
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<5;j++)
		{
			char a;
			cin>>a;
			if(a=='Y') days[j].person++;
		}
	}
	sort(days, days+5, cmp);
	for(long long i=0;i<5;i++)
	{
		if(i==0) cout<<days[i].daynum;
		else{
			if(days[i].person==days[i-1].person) cout<<','<<days[i].daynum;
			else break;
		}
	}
	return 0;
}
