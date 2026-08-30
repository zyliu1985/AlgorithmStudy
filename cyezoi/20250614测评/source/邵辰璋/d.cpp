#include <bits/stdc++.h>
using namespace std ;
long long g , p , x ;
int main ( ) {
	cin >> g >> p ;
	bool a [ g + 1 ] = { 0 } ;
	for ( int i = 1 ; i <= p ; i++ ) {
		cin >> x ;
		while ( a [ x ] == 1 ) x-- ;
		if ( x == 0 ) {
			cout << i - 1 ;
			break ;
		}
		a [ x ] = 1 ;
	}
}
