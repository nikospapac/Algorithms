#include <cstdio>
#include <vector>

using namespace std;

int count = 0;
int sum = 0;
int curr;

bool dfsSearch( vector<int> graph[], int N, int i, int j, int f) {
	if ( graph[ i ][ j ] <= 0 ) {
		return false;
	}
	else {
		graph[ i ][ j ] = 0;
		if ( i < N && j + 1 < N ) {
			dfsSearch( graph, N, i, j + 1, f + 1 );
		}
		if ( i + 1 < N && j < N ) {
			dfsSearch( graph, N, i + 1, j, f + 1 );
		}
		if ( i - 1 >= 0 && j < N ) {
			dfsSearch( graph, N, i - 1, j, f + 1 );
		}
		if ( i < N && j - 1 >= 0 ) {
			dfsSearch( graph, N, i, j - 1, f + 1 );
		}
		if ( f == 0 ) {
			++count;
			for ( i = 0; i < N; ++i ) {
				for ( j = 0; j < N; ++j ) {
					if ( graph[ i ][ j ] > 0 ) {
						sum -= graph[ i ][ j ];
						curr = ( i + 1 ) * ( j + 1 );
						dfsSearch( graph, N, i, j, f );
					}
				}
				if ( i + 1 == N ) {
					return true;
				}
			}
		}
	}
}

bool dfs( vector<int> graph[], int N ) {
	bool visited[ N + 1 ];
	int i, j, f = 0;
	for ( i = 0; i < N; ++i ) {
		visited[ i ] = false;
	}
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			if ( graph[ i ][ j ] != 0 ) {
				sum -= graph[ i ][ j ];
				return dfsSearch( graph, N, i, j, f );
			}
		}
		if ( i + 1 == N ) {
			return 0;
		}
	}
}

int main() {
	FILE *fin = fopen( "B.in", "r" );
	int n, k;
	fscanf( fin, "%d%d", &n, &k );
	vector< int > array[ n ];
	int i, j, u;

	for ( i = 0; i < n; ++i ) {
		for ( j = 0; j < n; ++j ) {
			fscanf( fin, "%d", &u );
			if ( u - k <= 0 ) {
				array[ i ].push_back( 0 );
			}
			else {
				array[ i ].push_back( u - k );
				sum += array[ i ][ j ];
			}
		}
	}
	
	dfs( array, n );
	fprintf( stdout, "%d\n", count );

	return 0;
}
