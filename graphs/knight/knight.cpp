#include <cstdio>
#include <queue>

using namespace std;

int dist[ 100 ][ 100 ];

void bfs( int x, int y ) {
	bool visited[ x ][ y ];
	int i, j;
	for ( i = 0; i < x; ++i ) {
		for ( j = 0; j < y; ++j ) {
			visited[ i ][ j ] = false;
		}
	}
	int n, m;
	queue<int> q;
	q.push( x - 1 );
	q.push( 0 );
	dist[ x - 1 ][ 0 ] = 0;
	int count = 0;
	while ( !q.empty() ) {
		m = q.front();
		q.pop();
		n = q.front();
		q.pop();
		visited[ m ][ n ] = true;
		if ( m - 1 >= 0 && n + 2 < y ) {
			if ( !visited[ m - 1 ][ n + 2 ] ) {
				q.push( m - 1 );
				q.push( n + 2 );
				dist[ m - 1 ][ n + 2 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m + 1 < x && n + 2 < y ) {
			if ( !visited[ m + 1 ][ n + 2 ] ) {
				q.push( m + 1 );
				q.push( n + 2 );
				dist[ m + 1 ][ n + 2 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m - 1 >= 0 && n - 2 >= 0 ) {
			if ( !visited[ m - 1 ][ n - 2 ] ) {
				q.push( m - 1 );
				q.push( n - 2 );
				dist[ m - 1 ][ n - 2 ] = dist[ m ][ n ] + 1;
			}	
		}
		if ( m + 1 < x && n - 2 >= 0 ) {
			if ( !visited[ m + 1 ][ n - 2 ] ) {
				q.push( m + 1 );
				q.push( n - 2 );
				dist[ m + 1 ][ n - 2 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m - 2 >= 0 && n + 1 < y ) {
			if ( !visited[ m - 2 ][ n + 1 ] ) {	
				q.push( m - 2 );
				q.push( n + 1 );
				dist[ m - 2 ][ n + 1 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m + 2 < x && n + 1 < y ) {
			if ( !visited[ m + 2 ][ n + 1 ] ) {
				q.push( m + 2 );
				q.push( n + 1 );
				dist[ m + 2 ][ n + 1 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m - 2 >= 0 && n - 1 >= 0 ) {
			if ( !visited[ m - 2 ][ n - 1 ] ) {
				q.push( m - 2 );
				q.push( n - 1 );
				dist[ m - 2 ][ n - 1 ] = dist[ m ][ n ] + 1;
			}
		}
		if ( m + 2 < 0 && n - 1 >= 0 ) {
			if ( !visited[ m + 2 ][ n - 1 ] ) {
				q.push( m + 2 );
				q.push( n - 1 );
				dist[ m + 2 ][ n - 1 ] = dist[ m ][ n ] + 1;
			}
		}
	}
}

int main() {
	FILE *fin = fopen( "knights.in", "r" );
	FILE *fout = fopen( "knights.out", "w" );
	int x, y;
	fscanf( fin, "%d%d", &x, &y );
	for ( int i = 0; i < x; ++i ) {
		for ( int j = 0; j < y; ++j ) {
			dist[ i ][ j ] = 0;
		}
	}

	bfs( x, y );

	fprintf( fout, "%d\n", dist[ 0 ][ y - 1 ] );

	return 0;
}
