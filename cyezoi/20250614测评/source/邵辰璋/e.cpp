#include <bits/stdc++.h>
using namespace std ;
int n , m , x [ 2005 ] [ 2005 ] , a , b , k , h , s , e , ans = 2147483647 ;
void ss ( int wz , int yh , int yw ) {
	if ( wz == e ) ans = min ( ans , yh ) ;
	else for ( int i = 1 ; i <= n ; i++ ) {
		if ( x [ wz ] [ i ] != 0 && i != yw ) ss ( i , yh + x [ wz ] [ i ] , wz ) ;
	}
}
int main ( ) {
	cin >> k >> n >> m ;
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> a >> b >> k >> h ;
		if ( h == 0 ) x [ b ] [ a ] = k ;
		if ( h == 0 ) x [ a ] [ b ] = k ;
	}
	cin >> s >> e ;
	ss ( s , 0 , 0 ) ;
	if ( ans == 2147483647 ) cout << -1 ;
	else cout << ans ;
}
