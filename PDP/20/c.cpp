#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int m = 0;
int N;

void printPath( int P[], int u ) {
	if ( P[ u ] != -1 ) {
		printf( "%d\n", P[ u ] );
		printPath( P, P[ u ] );
	}
}

bool dfs( int S, bool visited[], vector< int > graph[], int P[] ) {
	int i;
	stack< int > s;
	s.push( S );

	while ( !s.empty() ) {
		int p = s.top();
		s.pop();
		visited[ p ] = true;
		bool pushed = false;
		for ( i = 0; i < graph[ p ].size(); ++i ) {
			int k = graph[ p ][ i ];
			if ( !visited[ k ] ) {
				s.push( k );
				P[ k ] = p;
				pushed = true;
			}
			else {
				bool found = true;
				if ( k == S ) {
					for ( i = 1; i <= m; ++i ) {
						if ( !visited[ i ] ) {
							found = false;
							break;
						}
					}
					if ( found ) {
						printf( "%d\n", p );
						printPath( P, p );
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	freopen( "c.in", "r", stdin );
	freopen( "c.out", "w", stdout );
	int N, i;
	int u, v;
	vector< int > graph[ 1001 ];
	scanf( "%d", &N );

	for ( i = 0; i < N; ++i ) {
		scanf( "%d%d", &u, &v );
		graph[ u ].push_back( v );
		graph[ v ].push_back( u );
		if ( u > m ) {
			m = u;
		}
		if ( v > m ) {
			m = v;
		}
	}
	bool visited[ m + 1 ];
	int P[ m + 1 ];
	int j;
	for ( i = 1; i <= m; ++i ) {
		for ( j = 1; j <= m; ++j ) {
			visited[ j ] = false;
			P[ j ] = -1;
		}
		if ( dfs( i, visited, graph, P ) ) {
			break;
		}
		if ( i + 1 > m ) {
			printf( "0\n" );
		}
	}

	return 0;
}
