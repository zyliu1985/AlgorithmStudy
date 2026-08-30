#include <bits/stdc++.h>
using namespace std ;
int n , a [ 5005 ] [ 5005 ] , b [ 5005 ] , ans ;
int main ( ) {
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> b [ i ] ;
		for ( int j = 1 ; j <= i ; j++ ) {
			a [ i ] [ j ] = abs ( b [ i ] - b [ j ] ) ;
			a [ i ] [ j ] += a [ i - 1 ] [ j + 1 ] ;
		}
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			cout << a [ i ] [ j ] << ' ' ;
		}
		cout << endl ;
	}
	cout << 0 ;
	for ( int i = 2 ; i <= n ; i++ ) {
		ans = 2147483647 ;
		for ( int j = 1 ; j <= n - i + 1 ; j++ ) {
			ans = min ( ans , a [ j + i - 1 ] [ j ] ) ;
		}
		cout << ' ' << ans ;
	}
}
