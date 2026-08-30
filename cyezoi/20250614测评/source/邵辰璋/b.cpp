#include <bits/stdc++.h>
using namespace std ;
int c , ans ;
bool l1 [ 200001 ] , l2 [ 200001 ] ;
int main ( ) {
	cin >> c ;
	for ( int i = 1 ; i <= c ; i++ ) {
		cin >> l1 [ i ] ;
		if ( l1 [ i ] == 1 ) {
			ans += 3 ;
			if ( l1 [ i - 1 ] == 1 ) ans -= 2 ;
		}
	}
	for ( int i = 1 ; i <= c ; i++ ) {
		cin >> l2 [ i ] ;
		if ( l2 [ i ] == 1 ) {
			ans += 3 ;
			if ( l2 [ i - 1 ] == 1 ) ans -= 2 ;
			if ( l1 [ i ] == 1 && i % 2 ) ans -= 2 ;
		}
	}
	cout << ans ;
}
