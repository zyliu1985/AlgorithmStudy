#include <bits/stdc++.h>
using namespace std ;
struct d {
	int a , b ;
} x [ 6 ] ;
int n ;
char c ;
bool cmp ( d p , d q ) {
	return p . a > q . a ;
}
int main ( ) {
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> c ;
		if ( c == 'Y' ) x [ 1 ] . a ++ ;
		cin >> c ;
		if ( c == 'Y' ) x [ 2 ] . a ++ ;
		cin >> c ;
		if ( c == 'Y' ) x [ 3 ] . a ++ ;
		cin >> c ;
		if ( c == 'Y' ) x [ 4 ] . a ++ ;
		cin >> c ;
		if ( c == 'Y' ) x [ 5 ] . a ++ ;
	}
	x [ 1 ] . b = 1 ;
	x [ 2 ] . b = 2 ;
	x [ 3 ] . b = 3 ;
	x [ 4 ] . b = 4 ;
	x [ 5 ] . b = 5 ;
	sort ( x + 1 , x + 6 , cmp ) ;
	cout << x [ 1 ] . b ;
	for ( int i = 2 ; i <= 5 ; i++ ) {
		if ( x [ i ] . a == x [ 1 ] . a ) cout << ',' << x [ i ] . b ;
	}
}
