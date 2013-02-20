#include <cstdio>

using namespace std;

struct pos {
	int beg;
	int end;
};

int main() {
	int N, K = 0, M;
	scanf( "%d%d", &M, &N );
	pos array[ N ], in[ N ], out[ N ];
	int i, j, u, v;

	for ( i = 0; i < N; ++i ) {
		scanf( "%d%d", &u, &v );
		array[ i ].beg = u;
		array[ i ].end = v;
	}
	bool found;
	int finin = 0, finout = 0;
	for ( i = 0; i < N; ++i ) {
		found = true;
		for ( j = 0; j < finin; ++j ) {
			if ( array[ i ].beg > in[ j ].beg && array[ i ].end > in[ j ].end && in[ j ].end > array[ i ].beg ) {
				found = false;
				break;
			}
			if ( array[ i ].beg < in[ j ].beg && array[ i ].end < in[ j ].end ) {
				found = false;
				break;
			}
		}
		if ( found ) {
			in[ finin++ ] = array[ i ];
			++K;
			continue;
		}
		found = true;
		for ( j = 0; j < finout; ++j ) {
			if ( array[ i ].beg > out[ j ].beg && array[ i ].end > out[ j ].end && out[ j ].end > array[ i ].beg ) {
				found = false;
				break;
			}
			if ( array[ i ].beg < out[ j ].beg && array[ i ].end < out[ j ].end ) {
				found = false;
				break;
			}
		}
		if ( found ) {
			out[ finout++ ] = array[ i ];
			++K;
			continue;
		}
		if ( !found ) break;
	}
	printf( "%d\n", K );
}
