#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;


int main() {
	int m = 0, N, u, v, mx = 0, my = 0, i;
	map< int, int > x, y;
	scanf( "%d", &N );
	int posx[ N + 1 ], posy[ N + 1 ];
	for ( i = 0; i < N; ++i ) {
		scanf( "%d%d", &u, &v );
		if ( u > m ) {
			m = u;
		}
		if ( v > m ) {
			m = u;
		}
		if ( x[ u ] != 0 ) {
			if ( v < x[ u ] ) {
				x[ u ] = v;
			}
		}
		else {
			x[ u ] = v;
			posx[ mx ] = u;
			++mx;
		}
		if ( y[ v ] != 0 ) {
			if ( u < y[ v ] ) {
				y[ v ] = u;
			}
		}
		else {
			y[ v ] = u;
			posy[ my ] = v;
			++my;
		}
	}
	printf( "%d\n", m );
	printf( "%d %d\n", mx, my );
	sort( posx, posx + mx );
	sort( posy, posy + my );
	for ( i = 0; i < mx; ++i ) {
		printf( "%d %d\n", posx[ i ], m - ( x[ posx[ i ] ] - 1 ) );
	}
	for ( i = 0; i < my; ++i ) {
		printf( "%d %d\n", posy[ i ], m - ( y[ posy[ i ] ] - 1 ) );
	}
	

	return 0;
}
