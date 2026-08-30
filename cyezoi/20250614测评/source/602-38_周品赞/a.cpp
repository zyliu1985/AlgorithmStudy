#include "bits/stdc++.h"
using namespace std ;
const int N = 1e5 + 5 ;
int n, cnt[7], maxN ;
char ch ;
vector<int> maxP ;
int main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= 5 ; ++j)
		{
			cin >> ch ;
			if(ch == 'Y') cnt[j]++ ;
		}
	}
	for(int i = 1 ; i <= 5 ; ++i)
	{
		if(cnt[i] > maxN)
		{
			maxN = cnt[i] ;
			maxP.clear() ;
		}
		if(cnt[i] == maxN)
		{
			maxP.push_back(i) ;
		}
	}
	cout << maxP[0] ;
	for(int i = 1 ; i < maxP.size() ; ++i)
	{
		cout << "," << maxP[i] ;
	}
	return 0 ;
}
