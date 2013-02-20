#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen( "b.in", "r", stdin );
	freopen( "b.out", "w", stdout );
	int N, m1, m2;
	scanf( "%d", &N );
	bool visited[ N + 1 ];
	vector< int > pos[ N + 1 ];
	scanf( "%d%d", &m1, &m2 );
	int u, v, i;
	for ( i = 0; i <= N; ++i ) {
		visited[ i ] = false;
	}
	for ( i = 0; i < m1; ++i ) {
		scanf( "%d%d", &u, &v );
		visited[ N - ( v - 1 ) ] = true;
		pos[ u ].push_back( N - ( v - 1 ) );
	}

	for ( i = 0; i < m2; ++i ) {
		scanf( "%d%d", &u, &v );
		if ( !visited[ u ] ) {
			pos[ N - ( v - 1 ) ].push_back( u );
		}
	}
	int count = 0;
	for ( i = 1; i <= N; ++i ) {
		for ( int j = 0; j < pos[ i ].size(); ++j ) {
			++count;
		}
	}
	printf( "%d\n", count );
	for ( i = 1; i <= N; ++i ) {
		for ( int j = 0; j < pos[ i ].size(); ++j ) {
			printf( "%d %d\n", i, pos[ i ][ j ] );
		}
	}	

	return 0;
}
