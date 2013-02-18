#include <cstdio>
#include <algorithm>

using namespace std;

struct pos {
	int x;
	int y;
};

bool operator <( pos a, pos b ) {
	return a.x < b.x;
}

int main() {
	int N, i, j, k;
	bool found = false;
	scanf( "%d", &N );
	pos array[ N ];
	pos res[ N ];

	for ( i = 0; i < N; ++i ) {
		scanf( "%d%d", &array[ i ].x, &array[ i ].y );	
	}
	for ( i = 0, k = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			if ( array[ i ].x < array[ j ].x && array[ i ].y < array[ j ].y ) {
				found = true;
				break;
			}
		}
		if ( !found ) {
			res[ k++ ] = array[ i ];
		}
		found = false;
	}
	sort( res, res + k );
	printf( "\n" );
	for ( i = 0; i < k; ++i ) {
		printf( "%d %d\n", res[ i ].x, res[ i ].y );
	}

	return 0;
}
